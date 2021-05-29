#include "AI.hh"

class Game
{
private:
    Board *board;
    AI bot;
public:
    void start();
    void setSettings();
    void botMove();
    void play(int whoseTurn);
    void playerTurn();
    bool gameOver(int whoseTurn);
};

