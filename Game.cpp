#include "Game.hh"
#include <iostream>

#define PLAYER 0
#define BOT 1

void Game::start()
{
    setSettings();

    char cont = 'y';

    char choice;
    std::cout << "Do you want to start first? (y/n): ";
    std::cin >> choice;
    board->init();

    if (choice == 'n')
        play(BOT);
    else if (choice == 'y')
    {
        board->print();
        play(PLAYER);
    }
    else
        printf("Invalid choice\n");

    std::cout << "Do you want to quit? (y/n): ";
    std::cin >> cont;

    if (cont == 'n')
    {
        system("clear");
        start();
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Thanks for playing!" << std::endl;
    }
}

void Game::setSettings()
{
    int size, inRowToWin = 3;

    std::cout << "Choose size of the board - 3, 4 or 5" << std::endl;
    std::cout << "Board size: ";
    std::cin >> size;
    while (std::cin.fail() || size < 3 || size > 5)
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Invalid board size." << std::endl
                  << std::endl;
        std::cout << "Board size: ";
        std::cin >> size;
    }
    if (size > 3)
    {
        std::cout << "Choose number of signs in row to win - at least 3" << std::endl;
        std::cout << "Signs in row to win: ";
        std::cin >> inRowToWin;
        while (std::cin.fail() || inRowToWin < 3 || inRowToWin > size)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid number." << std::endl
                      << std::endl;
            std::cout << "Signs in row to win: ";
            std::cin >> inRowToWin;
        }
    }
    board = new Board(size, inRowToWin);
}

void Game::playerTurn()
{
    int row;
    int col;

    std::cout << "Select row: ";
    std::cin >> row;
    std::cout << "Select column: ";
    std::cin >> col;

    while (std::cin.fail())
    {
        board->print();
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Invalid input." << std::endl
                  << std::endl;
        std::cout << "Select row: ";
        std::cin >> row;
        std::cout << "Select column: ";
        std::cin >> col;
    }

    if (row > board->getSize() || row < 1 || col > board->getSize() || col < 1)
    {
        board->print();
        std::cout << "Invalid row or column number." << std::endl
                  << std::endl;
        playerTurn();
    }
    else
    {
        if (board->isFieldEmpty(row - 1, col - 1))
        {
            board->makeMove(row, col, 'X');
        }
        else
        {
            board->print();
            std::cout << "This field is already taken." << std::endl
                      << std::endl;
            playerTurn();
        }
    }
}

bool Game::gameOver(int whoseTurn)
{
    if (bot.evaluate(*board))
    {
        if (whoseTurn == BOT)
        {
            std::cout << "You lost!" << std::endl;
            return true;
        }
        else
        {
            std::cout << "You won!" << std::endl;
            return true;
        }
    }
    return false;
}

void Game::play(int whoseTurn)
{
    int moveIndex = 0;

    while (!bot.evaluate(*board) && moveIndex < board->getSize() * board->getSize())
    {
        if (whoseTurn == BOT)
        {
            bot.findBestMove(*board, moveIndex);
            moveIndex++;
            whoseTurn = PLAYER;
        }
        else if (whoseTurn == PLAYER)
        {
            playerTurn();
            moveIndex++;
            whoseTurn = BOT;
        }
    }
    if (!gameOver(!whoseTurn))
    {
        std::cout << "It's a draw" << std::endl;
    }
}