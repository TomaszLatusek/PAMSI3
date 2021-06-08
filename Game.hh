#include "AI.hh"

class Game
{
private:
    Board *board;
    AI bot;
    Move playerLastMove;

public:
    Game() { playerLastMove.row = 0, playerLastMove.col = 0; };
    void start();
    void setSettings();
    void botMove();
    void play(int whoseTurn);
    void playerTurn();
    bool gameOver(int whoseTurn);
};
