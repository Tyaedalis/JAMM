/*
	main.cpp
	Program entry point, initialization of main game class JAMMgame
*/

#include "JAMMgame.h"
#include "caveGen.h"

#include <iostream>

int main(void)
{
    std::cout << "Initializing main game class ...\n";
    
    JAMM::Game game;
    game.InitializeWindow();
    game.Start();

    return 0;
}
