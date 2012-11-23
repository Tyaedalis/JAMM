/*
	Game.cpp
	Contains main game class, JAMM::Game.
*/

#include "Game.h"

using namespace JAMM;

// Default constructor
Game::Game() { }

void Game::InitializeComponents()
{
    Log << "\n============= Begin Startup =============\n";

    Log << "Initializing game window ... ";
    GameWindow = new sf::RenderWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "Project JAMM");
    if (GameWindow->isOpen()) 
        Log << "Done.\n";
    else
        ExitWithError("Failed to create render window.");

    Log << "Initializing memory manager ... ";
    MemManager = new MemoryManager();
    if (MemManager->Initialize())
        Log << "Done.\n";
    else
        ExitWithError("Failed to initialize memory manager.");

    // Test memory management
    MemoryPool testPool(4, 10); // creates a memory pool for 10 objects that are up to 2 bytes large
    testPool.alloc<int>();

    Log << "Loading configuration file ...\n";
    Config = new ConfigFile(CONFIG_FILENAME);     // Test config functionality
    Config->parseFile();

    Log << "\n============= End Startup =============\n\n";
}

void Game::ShutdownComponents()
{
    GameWindow->close();
    delete GameWindow;

    MemManager->Shutdown();
    delete MemManager;
}

// Public method to start the game and run the main loop
int32 Game::Start()
{
    return Game::mainLoop();
}

// Private main loop function
int32 Game::mainLoop()
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