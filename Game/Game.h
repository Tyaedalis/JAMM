/*
	Game.h
	Header file for main game class, JAMM::Game.
*/

#pragma once

#include <SFML\Graphics.hpp>

#include "Game\AtomicTypes.h"
#include "Game\Components\MemoryManager.h"
#include "Game\Components\ConfigFile.h"
#include "Game\Debug\Debug.h"

const std::wstring Config_Filename = L"DefaultConfig.x";

namespace JAMM
{
    /*
	==========================
    class Game
	Main game class, connects all of the game sub-components together
    ==========================
    */
    class Game
    {
        public:
            // Pointer to the game render window
            sf::RenderWindow* GameWindow;
            MemoryManager* MemManager;

            // Default constructor
            Game();

            void InitializeComponents();
            void ShutdownComponents();

            int32 Start();
        private:
            uint32 _screenWidth;
            uint32 _screenHeight;

            int32 mainLoop();
    };
}