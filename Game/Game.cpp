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
    Log << L"\n============= Begin Startup =============\n";

    Log << L"Initializing game window ... ";
    GameWindow = new sf::RenderWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "Project JAMM");
    if (GameWindow->isOpen()) 
        Log << L"Done.\n";
    else
        ExitWithError("Failed to create render window.");

    Log << L"Initializing memory manager ... ";
    MemManager = new MemoryManager();
    if (MemManager->Initialize())
        Log << L"Done.\n";
    else
        ExitWithError("Failed to initialize memory manager.");

    Log << L"Loading configuration file ...\n";
    Config = new ConfigFile(Config_Filename);     // Test config functionality
    Config->parseFile();

    Log << L"\n============= End Startup =============\n\n";
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
    Log << L"Entering main loop ...\n";
    
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