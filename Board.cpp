#include <string>
#include <iostream>
#include "Board.hh"

Board::Board(int s, int irtw)
{
    size = s;
    inRowToWin = irtw;

    fields = new char *[size];

    for (int i = 0; i < size; i++)
    {
        fields[i] = new char[size];
        for (int j = 0; j < size; j++)
        {
            fields[i][j] = ' ';
        }
    }
}

Board::~Board()
{
    // for (int i = 0; i < size; i++)
    // {
    //     delete fields[i];
    // }
    // delete fields;
}

void Board::init()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fields[i][j] = ' ';
        }
    }
}

bool Board::isFieldEmpty(int i, int j)
{
    if (fields[i][j] == ' ')
        return true;
    else
        return false;
}

void Board::print()
{
    system("clear");

    for (int i = 0; i < 6 * size; i++)
    {
        if (i % 6 == 3)
        {
            std::cout << i / 6 + 1;
        }
        else
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    for (int i = 1; i < 4 * size; i++)
    {
        if (i % 4 == 2)
        {
            std::cout << i / 4 + 1;
        }
        else
        {
            std::cout << " ";
        }

        for (int j = 0; j < 6 * size - 1; j++)
        {
            if (i % 4 == 0)
            {
                std::cout << "-";
            }
            else if (j % 6 == 5)
            {
                std::cout << "|";
            }
            else if (i % 4 == 2 && j % 6 == 2)
            {
                std::cout << fields[i / 4][j / 6];
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Board::makeMove(int row, int column, char sign)
{
    if (fields[row - 1][column - 1] == 'X' || fields[row - 1][column - 1] == 'O')
    {
        std::cout << "Field already taken" << std::endl;
    }
    else
    {
        fields[row - 1][column - 1] = sign;
        print();
    }
}