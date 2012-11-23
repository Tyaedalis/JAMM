/*
	Game.cpp
	Contains main game class, JAMM::Game.
*/

#include "Game.h"

using namespace JAMM;

// Default constructor
Game::Game() { }

void testMemoryPool()
{
    Log << "\n\n- Starting memory pool test - \n" <<
        "Attempting to allocate a memory pool that can hold up to of 3 integer variables.\n\n";

    // Test memory management
    MemoryPool testPool(4, 3); // creates a memory pool for up to 3 objects that are up to 4 bytes (integer) large

    int* testInt = (int*)testPool.alloc<int>(); // Request a few memory blocks from the pool
    int* testInt2 = (int*)testPool.alloc<int>();
    int* testInt3 = (int*)testPool.alloc<int>();

    *testInt = 21; // Test variable functionality
    *testInt2 = 32;
    *testInt3 = 43;

    Log << "Requesting 3 memory blocks ...\n\n"
        << "var 1. addr: " << testInt << " val: " << *testInt << "\n"
        << "var 2. addr: " << testInt2 << " val: " << *testInt2 << "\n"
        << "var 3. addr: " << testInt3 << " val: " << *testInt3 << "\n";

    Log << "\nReleasing variable 2's memory. Success: " <<
        testPool.free((ptr32)testInt2) << "\n\n";

    Log << "Attempting to re-release variable 2's memory. This should fail. Success: " <<
        testPool.free((ptr32)testInt2) << "\n\n";

    Log << "Requesting another memory block...\n";
    testInt2 = (int*)testPool.alloc<int>();

    if (testInt2 != NULL)
        Log << "Success! Address: " << testInt2 << "\n\n";
    else
        Log << "Failed!\n\n";

    Log << "Requesting a 4th memory block... This should fail.\n";
    int* testInt4 = (int*)testPool.alloc<int>();

    if (testInt4 != NULL)
        Log << "Success! Address: " << testInt4 << "\n\n";
    else
        Log << "Failed!\n\n";

    Log << "\n- End memory pool test - \n\n";
}

void Game::InitializeComponents()
{
    Log << "\n============= Begin Startup =============\n";

    Log << "Initializing game window ... ";
    GameWindow = new sf::RenderWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "Project JAMM");
    if (GameWindow->isOpen()) 
        Log << "Done.\n";
    else
        ExitWithError("Failed to create render window.");

    Log << "Initializing memory manager ... ";
    MemManager = new MemoryManager();
    if (MemManager->Initialize())
        Log << "Done.\n";
    else
        ExitWithError("Failed to initialize memory manager.");

    testMemoryPool(); // Test creating and using a memory pool

    Log << "Loading configuration file ...\n";
    Config = new ConfigFile(CONFIG_FILENAME);     // Test config functionality
    Config->parseFile();

    Log << "\n============= End Startup =============\n\n";
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
    Log << "Entering main loop ...\n";
    
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