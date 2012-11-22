/*
	Game.cpp
	Contains main game class, JAMM::Game.
*/

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"
#include "Components\config.h"
#include "Components\MemoryManager.h"

using namespace JAMM;

// Default constructor
Game::Game() { }

// Function to initialize game window
int Game::InitializeWindow()
{
    std::cout << "Initializing game window ...\n";
    GameWindow = new sf::RenderWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "Project JAMM");
    
    return 1;
}

int Game::InitializeComponents()
{
    std::cout << "Initializing memory manager ...\n";
    MemManager = new MemoryManager();
    MemManager->Initialize();

    // Test memory management
    MemoryPool testPool(2, 10); // creates a memory pool for 10 objects that are up to 2 bytes large
    testPool.alloc<int>();

    std::cout << "Loading configuration file ...\n";
    ConfigFile config = ConfigFile();     // Test config functionality
    config.parseFile();

    return 1;
}

int Game::ShutdownComponents()
{
    MemManager->Shutdown();
    delete MemManager;

    return 1;
}

int Game::ShutdownWindow()
{
    GameWindow->close();
    delete GameWindow;

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
    std::cout << "Entering main loop ...\n";
    
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