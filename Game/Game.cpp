/*
	Game.cpp
	Contains main game class, JAMM::Game.
*/

#include "Game.h"

using namespace JAMM;

// Default constructor
Game::Game() { }

int Game::InitializeComponents()
{
    Log << "\n============= Begin Startup =============\n";

    Log << "Initializing game window ...\n";
    GameWindow = new sf::RenderWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "Project JAMM");

    Log << "Initializing memory manager ...\n";
    MemManager = new MemoryManager();
    MemManager->Initialize();

    // Test memory management
    MemoryPool testPool(2, 10); // creates a memory pool for 10 objects that are up to 2 bytes large
    testPool.alloc<int>();

    Log << "Loading configuration file ...\n";
    ConfigFile config = ConfigFile();     // Test config functionality
    config.parseFile();

    Log << "\n============= End Startup =============\n\n";

    return 1;
}

int Game::ShutdownComponents()
{
    GameWindow->close();
    delete GameWindow;

    MemManager->Shutdown();
    delete MemManager;

    return 1;
}

// Public method to start the game and run the main loop
int Game::Start()
{
    return Game::mainLoop();
}

// Private main loop function
int Game::mainLoop()
{
    Log << "Entering main loop ...\n";
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    while (GameWindow->isOpen())
    {
        sf::Event event;
        while (GameWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                GameWindow->close();
        }

        GameWindow->clear();
        GameWindow->draw(shape);
        GameWindow->display();
    }

    return 1;
}