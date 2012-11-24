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

            int32 Start();
        private:
            int32 mainLoop();
    };
}