/*
	caveGen.h
	Header file for cave generation file caveGen.cpp. Contains classes.
*/

#pragma once

class Point // An ordered pair of ints
{
public:
	// Contructors
	Point ();
	Point(int, int);

	// Operators
	Point operator + (Point);
	Point operator - (Point);

	// Variables
	int x, y;
};

class Grid // Grid for diggers to operate on
{
public:
	//Constructors
	Grid ();			// Default size
	Grid (int);			// Square
	Grid (int, int);	// Rectangle

	// Member functions
	void setAt(Point, char);	// Set a cell to a char
	Point inBounds(Point);		// Validates a Point. Returns a point in bounds.

	// Variables
	int width, height;
};