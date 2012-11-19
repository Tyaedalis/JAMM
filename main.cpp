/*
	main.cpp
	Program entry point, initialization of main game class JAMMgame
*/

#include <iostream>
#include "Game\Game.h"

int main(void)
{
    std::cout << "Initializing main game class ...\n";
    
    // Create main game class
    JAMM::Game game;

    // Initialize components
    game.InitializeWindow();

    // Start the game
    game.Start();

    // Shutdown components and release memory
    game.ShutdownWindow();

    return 0;
}
