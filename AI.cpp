#include "AI.hh"
#include <algorithm>
#include <iostream>

bool AI::isMoveLeft(Board board)
{
    for (int i = 0; i < board.size; i++)
    {
        for (int j = 0; j < board.size; j++)
        {
            if (board.fields[i][j] == ' ')
            {
                return true;
            }
        }
    }

    return false;
}

bool AI::evaluate(Board board)
{
    int counter;

    // checking rows for victory
    for (int row = 0; row < board.size; row++)
    {
        counter = 0;
        char prevRow = ' ';

        for (int j = 0; j < board.size; j++)
        {
            if (board.fields[row][j] != ' ')
            {
                if (board.fields[row][j] == prevRow)
                {
                    counter++;
                }
                else
                {
                    counter = 1;
                }
            }

            if (counter >= board.inRowToWin)
                return true;

            prevRow = board.fields[row][j];
        }
    }

    // checking columns for victory
    for (int column = 0; column < board.size; column++)
    {
        counter = 0;
        char prevRow = ' ';

        for (int i = 0; i < board.size; i++)
        {
            if (board.fields[i][column] != ' ')
            {
                if (board.fields[i][column] == prevRow)
                {
                    counter++;
                }
                else
                {
                    counter = 1;
                }
            }

            if (counter >= board.inRowToWin)
                return true;

            prevRow = board.fields[i][column];
        }
    }

    // checking first diagonal for victory
    int counterD, counterU;
    char prevDiagonalD, prevDiagonalU;
    for (int k = board.size % board.inRowToWin; k >= 0; k--)
    {
        counterD = counterU = 0;
        prevDiagonalD = prevDiagonalU = ' ';
        for (int i = k; i < board.size; i++)
        {
            if (board.fields[i][i - k] != ' ')
            {
                if (board.fields[i][i - k] == prevDiagonalD)
                {
                    counterD++;
                }
                else
                {
                    counterD = 1;
                }
            }

            if (counterD >= board.inRowToWin)
                return true;

            if (board.fields[i - k][i] != ' ')
            {
                if (board.fields[i - k][i] == prevDiagonalU)
                {
                    counterU++;
                }
                else
                {
                    counterU = 1;
                }
            }

            if (counterU >= board.inRowToWin)
                return true;

            prevDiagonalD = board.fields[i][i - k];
            prevDiagonalU = board.fields[i - k][i];
        }
    }

    // checking second diagonal for victory
    for (int k = 0; k < board.size * 2; k++)
    {
        char prev = ' ';
        counter = 0;
        for (int j = 0; j <= k; j++)
        {
            int i = k - j;
            if (i < board.size && j < board.size)
            {
                if (board.fields[i][j] != ' ')
                {
                    if (board.fields[i][j] == prev)
                    {
                        counter++;
                    }
                    else if (prev == ' ')
                    {
                        counter = 1;
                    }
                    else
                    {
                        counter = 0;
                    }
                }

                if (counter >= board.inRowToWin)
                    return true;

                prev = board.fields[i][j];
            }
        }
    }

    // if there's no victory
    return false;
}

int AI::minimax(Board board, int depth, bool isAI)
{
    int score = 0;
    int bestScore = 0;
    if (evaluate(board))
    {
        // std::cout << "Evaluated" << std::endl;
        if (isAI == true)
            return -1;
        if (isAI == false)
            return +1;
    }
    else
    {
        if (depth < board.size * board.size && depth > board.size * board.size - 10)
        {
            if (isAI == true)
            {
                bestScore = -999;
                for (int i = 0; i < board.size; i++)
                {
                    for (int j = 0; j < board.size; j++)
                    {
                        if (board.fields[i][j] == ' ')
                        {
                            board.fields[i][j] = 'O';
                            score = minimax(board, depth + 1, false);
                            board.fields[i][j] = ' ';
                            if (score > bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                bestScore = 999;
                for (int i = 0; i < board.size; i++)
                {
                    for (int j = 0; j < board.size; j++)
                    {
                        if (board.fields[i][j] == ' ')
                        {
                            board.fields[i][j] = 'X';
                            score = minimax(board, depth + 1, true);
                            board.fields[i][j] = ' ';
                            if (score < bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
        }
        else
        {
            return 0;
        }
    }
}

void AI::findBestMove(Board board, int moveIndex)
{
    int x = -1, y = -1;
    int score = 0, bestScore = -999;
    // Move bestMove;

    if (board.size * board.size - moveIndex < 10)
    {
        for (int i = 0; i < board.size; i++)
        {
            for (int j = 0; j < board.size; j++)
            {
                if (board.fields[i][j] == ' ')
                {
                    board.fields[i][j] = 'O';
                    score = minimax(board, moveIndex + 1, false);
                    board.fields[i][j] = ' ';
                    if (score > bestScore)
                    {
                        bestScore = score;
                        x = i;
                        y = j;
                        // bestMove.row = i;
                        // bestMove.col = j;
                    }
                }
            }
        }
        board.makeMove(x + 1, y + 1, 'O');
    }
    else
        findBestMove(board, board.size * board.size - 3);
}

void AI::randomMove(Board board)
{
    int row = rand() % board.size;
    int col = rand() % board.size;

    if (board.fields[row][col] == ' ')
    {
        board.makeMove(row + 1, col + 1, 'O');
    }
}
