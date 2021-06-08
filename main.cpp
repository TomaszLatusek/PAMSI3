#include "Game.hh"
#include <iostream>

int main()
{
    Game *game = new Game();

    system("clear");
    std::cout << "------------------------------------" << std::endl;
    std::cout << "--------- Tic Tac Toe Game ---------" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << std::endl;
    game->start();
}