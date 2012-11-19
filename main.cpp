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

    // Initialize game components
    game.InitializeWindow();
    game.InitializeComponents();

    // Start the game
    game.Start();

    // Shutdown and release game components
    game.ShutdownWindow();
    game.ShutdownComponents();

    return 0;
}
