/*
	Game.h
	Header file for main game class, JAMM::Game.
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "AtomicTypes.h"
#include "Components\MemoryManager.h"
#include "Components\config.h"
#include "Debug\Debug.h"

const std::wstring Config_Filename = L"DefaultConfig.x";

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

            void InitializeComponents();
            void ShutdownComponents();

            int32 Start();
        private:
            uint32 _screenWidth;
            uint32 _screenHeight;

            int32 mainLoop();
    };
}