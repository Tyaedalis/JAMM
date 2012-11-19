/*
	Game.h
	Header file for main game class, JAMM::Game.
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Components\MemoryManager.h"

#define ScreenWidth 800
#define ScreenHeight 600

namespace JAMM
{
    class Game
    {
        public:
            // Pointer to the game render window
            sf::RenderWindow* GameWindow;
            MemoryManager* MemManager;

            // Default constructor
            Game();

            int InitializeWindow();
            int InitializeComponents();
            int ShutdownWindow();
            int ShutdownComponents();

            int Start();
        private:
            int mainLoop();
    };
}