#include "Board.hh"

struct Move
{
    int row, col;
};

class AI
{
public:
    bool isMoveLeft(Board board);
    bool evaluate(Board board);
    int minimax(Board board, int depth, bool isAI);
    Move findBestMove(Board board, int moveIndex);
    // bool gameOver(Board board);
};
