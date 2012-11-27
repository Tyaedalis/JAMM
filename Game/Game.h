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
        private:
            uint32 _screenWidth;
            uint32 _screenHeight;

            int32 mainLoop();

            // Prevent compiler from generating default copy constructor\copy assignment operator code
            Game(const Game&);
            Game& operator=(const Game&);
        public:
            // Pointer to the game render window
            sf::RenderWindow* GameWindow;

            // Default constructor
            Game();

            void InitializeComponents();
            void ShutdownComponents();

            int32 Start();
    };

    /*
    ==========================
    Game& gGame();
    Function declared in namespace scope that returns a global static instance of the default Game class
    ==========================
    */
    Game& gGame();
}