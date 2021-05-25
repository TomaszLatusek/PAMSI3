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

int AI::evaluate(Board board)
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
            if (prevRow == 'X')
                return 10;

            if (prevRow == 'O')
                return -10;
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
            if (prevCol == 'X')
                return 10;

            else if (prevCol == 'O')
                return -10;
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
        if (prevDiagonal == 'X')
            return 10;

        else if (prevDiagonal == 'O')
            return -10;
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
        if (prevDiagonal == 'X')
            return 10;

        else if (prevDiagonal == 'O')
            return -10;
    }

    // if there's no victory
    return 0;
}

int AI::minimax(Board board, int depth, bool isMax)
{
    int score = evaluate(board);

    if (score != 0)
        return score;

    if (isMoveLeft(board) == false)
        return 0;

    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i < board.size; i++)
        {
            for (int j = 0; j < board.size; j++)
            {
                // Check if cell is empty
                if (board.fields[i][j] == ' ')
                {
                    // Make the move
                    board.fields[i][j] = 'X';

                    // Call minimax recursively and choose
                    // the maximum value
                    best = std::max(best,
                                    minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board.fields[i][j] = ' ';
                }
            }
        }
        return best;
    }

    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i < board.size; i++)
        {
            for (int j = 0; j < board.size; j++)
            {
                // Check if cell is empty
                if (board.fields[i][j] == ' ')
                {
                    // Make the move
                    board.fields[i][j] = 'O';

                    // Call minimax recursively and choose
                    // the minimum value
                    best = std::min(best,
                                    minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board.fields[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

Move AI::findBestMove(Board board)
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i < board.size; i++)
    {
        for (int j = 0; j < board.size; j++)
        {
            // Check if cell is empty
            if (board.fields[i][j] == ' ')
            {
                // Make the move
                board.fields[i][j] = 'O';

                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);

                // Undo the move
                board.fields[i][j] = ' ';

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    std::cout << "The value of the best Move is: " << bestVal << std::endl;
    std::cout << "Move " << bestMove.row + 1 << "-" << bestMove.col + 1 << std::endl;

    return bestMove;
}