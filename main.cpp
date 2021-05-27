//#include "Board.hh"
#include "AI.hh"
#include <iostream>

int main()
{
    Board *board = new Board(4, 3);
    AI ai;

    board->makeMove(1, 1, 'O');
    board->makeMove(1, 2, 'O');
    board->makeMove(1, 3, 'O');
    board->makeMove(1, 4, 'X');
    // board->makeMove(1, 5, ' ');

    board->makeMove(2, 1, 'O');
    board->makeMove(2, 2, 'O');
    board->makeMove(2, 3, 'O');
    board->makeMove(2, 4, 'X');
    // board->makeMove(2, 5, ' ');

    board->makeMove(3, 1, 'X');
    board->makeMove(3, 2, 'X');
    board->makeMove(3, 3, 'X');
    board->makeMove(3, 4, 'O');
    // board->makeMove(3, 5, ' ');

    board->makeMove(4, 1, 'X');
    board->makeMove(4, 2, 'X');
    board->makeMove(4, 3, ' ');
    board->makeMove(4, 4, ' ');
    // board->makeMove(4, 5, ' ');

    // board->makeMove(5, 1, ' ');
    // board->makeMove(5, 2, ' ');
    // board->makeMove(5, 3, ' ');
    // board->makeMove(5, 4, ' ');
    // board->makeMove(5, 5, ' ');

    ai.findBestMove(*board, 14);
}