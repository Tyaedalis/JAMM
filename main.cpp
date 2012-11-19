/*
	main.cpp
	Program entry point, initialization of main game class JAMM::Game
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

    std::cout << "Shutting down game ...\n";

    // Shutdown and release game components
    game.ShutdownWindow();
    game.ShutdownComponents();

    return 0;
}
