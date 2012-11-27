/*
	main.cpp
	Program entry point, initialization of main game class JAMM::Game
*/

#include "Game\Game.h"

/*
	==========================
    int main(void)
	Program entry point, initialization of main game class JAMM::Game
    ==========================
*/
int main(void)
{
    ASSERT(sizeof(float) == 4, "Checking if float is 4 bytes wide");

    Log << L"Initializing main game class ...\n";
    
    // Create main game class
    JAMM::Game game;

    // Test debug functionality!
    // DEBUG_BREAK; // Causes the program to halt and create a breakpoint here
    // ASSERT(false, "This is a test assertion."); // Allows the program to evaluate an expression and causes a breakpoint if it fails
    // ExitWithError("This is a test fatal error."); // Allows the program to exit on a fatal error with a message

    // Initialize game components
    game.InitializeComponents();

    // Start the game
    game.Start();

    Log << L"Shutting down game ...\n";

    // Shutdown and release game components
    game.ShutdownComponents();

    return 0;
}
