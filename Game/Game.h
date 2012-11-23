/*
	Game.h
	Header file for main game class, JAMM::Game.
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Components\MemoryManager.h"
#include "Components\config.h"
#include "Debug\Debug.h"

#define CONFIG_FILENAME "DefaultConfig.x"
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
            ConfigFile* Config;

            // Default constructor
            Game();

            void InitializeComponents();
            void ShutdownComponents();

            int Start();
        private:
            int mainLoop();
    };
}