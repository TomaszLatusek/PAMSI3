//#include "Board.hh"
#include "AI.hh"
#include <iostream>

int main()
{
    Board *board = new Board(3, 3);
    AI ai;

    board->makeMove(1, 1, 'O');
    board->makeMove(1, 2, 'O');
    board->makeMove(1, 3, 'X');

    board->makeMove(2, 1, ' ');
    board->makeMove(2, 2, ' ');
    board->makeMove(2, 3, ' ');

    board->makeMove(3, 1, 'X');
    board->makeMove(3, 2, ' ');
    board->makeMove(3, 3, 'X');

    ai.findBestMove(*board);
}