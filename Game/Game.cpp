/*
	Game.cpp
	Contains main game class, JAMM::Game.
*/

#include "Game\Game.h"

using namespace JAMM;

/*
==========================
Game::Game()
Default constructor for the Game class, initializes member variables
==========================
*/
Game::Game()
    : _screenWidth(800),
      _screenHeight(600)
{ Log << L"Initializing main Game class ...\n"; }

/*
==========================
void Game::InitializeComponents()
Function that is called from main() to initialize the game sub-systems
==========================
*/
void Game::InitializeComponents()
{
    Log << L"\n============= Begin Startup =============\n";

    _screenWidth = gConfiguration().GetValue<uint32>(L"gScreenWidth", _screenWidth);
    _screenHeight = gConfiguration().GetValue<uint32>(L"gScreenHeight", _screenHeight);

    Log << L"Initializing game window ... ";
    GameWindow = new sf::RenderWindow(sf::VideoMode(_screenWidth, _screenHeight), "Project JAMM");
    if (GameWindow->isOpen()) 
        Log << L"Done.\n";
    else
        ExitWithError("Failed to create render window.");


    Log << L"\n============= End Startup =============\n\n";
}

/*
==========================
void Game::ShutdownComponents()
Function that is called from main() to properly shutdown the game sub-systems, and disposes of resources
==========================
*/
void Game::ShutdownComponents()
{
    GameWindow->close();
    delete GameWindow;

    gMemoryManager().Shutdown();
}

/*
==========================
int32 Game::Start()
Function that is called from main() to start the game
==========================
*/
int32 Game::Start()
{
    return Game::mainLoop();
}

/*
==========================
int32 Game::mainLoop()
Private function which contains the main game loop that updates and renders the game
==========================
*/
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

/*
==========================
Game& JAMM::gGame()
Function implemented in namespace scope that returns a global static instance of the default Game class
==========================
*/
Game& JAMM::gGame()
{
    static Game Game;
    return Game;
}