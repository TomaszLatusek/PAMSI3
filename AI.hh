#include "Board.hh"

struct Move
{
    int row, col;
};

class AI
{
public:
    bool isMoveLeft(Board board);
    int evaluate(Board board);
    int minimax(Board board, int depth, bool isMax);
    Move findBestMove(Board board);
};
