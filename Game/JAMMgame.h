/*
	JAMMgame.h
	Header file for main game class, JAMMgame.
*/

#include <SFML/Graphics.hpp>

#pragma once

#define ScreenWidth 800
#define ScreenHeight 600

namespace JAMM
{
    class Game
    {
	    public:
		    // Pointer to the game render window
		    sf::RenderWindow* GameWindow;

		    // Default constructor
		    Game();

	        int InitializeWindow();
		    int Start();
	    private:
		    int mainLoop();
    };
}