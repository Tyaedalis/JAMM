/*
	main.cpp
	Program entry point, initialization of main game class JAMMgame
*/

#include "JAMMgame.h"
#include "caveGen.h"

#include <iostream>

int main(void)
{
    std::cout << "Initializing main game class ...\n";
	
	// Testing my class...
	Point point1 (1, 2);
	Point point2 (3, 3);
	Point sum = point1 + point2; // should be Point (4, 5)
	Point sub = sum - point1; // should be Point (3, 3)
	std::cout << "\nPoint: " << point1.x << ", " << point1.y << "\n";
	std::cout << "\nPoint: " << point2.x << ", " << point2.y << "\n";
	std::cout << "\nPoint: " << sum.x << ", " << sum.y << "\n";
	std::cout << "\nPoint: " << sub.x << ", " << sub.y << "\n";

    JAMMgame game;
    game.InitializeWindow();
    game.Start();

    return 0;
}
