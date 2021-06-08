#include "Board.hh"
#include <stdlib.h>

struct Move
{
    int row, col;
};

class AI
{
public:
    bool isMoveLeft(Board board);
    bool evaluate(Board board, int i, int j);
    int minimax(Board board, int depth, bool isAI, Move playerLastMove);
    void randomMove(Board board);
    void findBestMove(Board board, int moveIndex, Move playerLastMove);
};
