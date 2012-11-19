/*
	JAMMgame.cpp
	Contains main game class, JAMMgame.
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "JAMMgame.h"

using namespace JAMM;

// Default constructor
Game::Game()
{
    
}

// Function to initialize game window
int Game::InitializeWindow()
{
    std::cout << "Initializing game window ...\n";
    GameWindow = new sf::RenderWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "Project JAMM");
    
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