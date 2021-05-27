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
        counter = 1;
        char prevRow = board.fields[row][0];
        if (prevRow != ' ')
        {
            for (int j = 1; j < board.size; j++)
            {
                if (board.fields[row][j] == prevRow)
                {
                    counter++;
                    prevRow = board.fields[row][j];
                }
                else
                    break;
            }
        }
        else
            continue;

        if (counter == board.size)
        {
            if (prevRow != ' ')
                return true;

            // if (prevRow == 'O')
            //     return -10;
        }
    }

    // checking columns for victory
    for (int column = 0; column < board.size; column++)
    {
        counter = 1;
        char prevCol = board.fields[0][column];
        if (prevCol != ' ')
        {
            for (int j = 1; j < board.size; j++)
            {
                if (board.fields[j][column] == prevCol)
                {
                    counter++;
                    prevCol = board.fields[j][column];
                }
                else
                    break;
            }
        }
        else
            continue;
        if (counter == board.size)
        {
            if (prevCol != ' ')
                return true;

            // if (prevCol == 'O')
            //     return -10;
        }
    }

    // checking first diagonal for victory
    counter = 1;
    char prevDiagonal = board.fields[0][0];
    for (int i = 1; i < board.size; i++)
    {
        if (prevDiagonal != ' ')
        {
            if (board.fields[i][i] == prevDiagonal)
            {
                counter++;
                prevDiagonal = board.fields[i][i];
            }
            else
                break;
        }
        else
            break;
    }
    if (counter == board.size)
    {
        if (prevDiagonal != ' ')
            return true;

        // if (prevDiagonal == 'O')
        //     return -10;
    }

    // checking second diagonal for victory
    counter = 1;
    int tmp = 0;
    prevDiagonal = board.fields[tmp][board.size - 1];
    for (int i = board.size - 2; i >= 0; i--)
    {
        tmp++;
        if (prevDiagonal != ' ')
        {
            if (board.fields[tmp][i] == prevDiagonal)
            {
                counter++;
                prevDiagonal = board.fields[tmp][i];
            }
            else
                break;
        }
        else
            break;
    }
    if (counter == board.size)
    {
        if (prevDiagonal != ' ')
            return true;

        // if (prevDiagonal == 'O')
        //     return -10;
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

Move AI::findBestMove(Board board, int moveIndex)
{
    int x = -1, y = -1;
    int score = 0, bestScore = -999;
    Move bestMove;

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
                    bestMove.row = i;
                    bestMove.col = j;
                }
            }
        }
    }

    // std::cout << "The value of the best Move is: " << bestScore << std::endl;
    std::cout << "Move " << bestMove.row + 1 << "-" << bestMove.col + 1 << std::endl;

    return bestMove;
}