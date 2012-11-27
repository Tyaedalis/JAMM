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
    // Initialize game components
    JAMM::gGame().InitializeComponents();

    // Start the game
    JAMM::gGame().Start();

    Log << L"Shutting down game ...\n";

    // Shutdown and release game components
    JAMM::gGame().ShutdownComponents();

    return 0;
}
