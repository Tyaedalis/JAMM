/*
	caveGen.cpp
	Code for cave generator.
*/

#include "caveGen.h"

// Point class
Point::Point ()
{
	x = 0;
	y = 0;
}

Point::Point (int X, int Y)
{
	x = X;
	y = Y;
}

Point Point::operator+ (Point other)
{
	Point temp;
	temp.x = x + other.x;
	temp.y = y + other.y;
	return (temp);
}

Point Point::operator- (Point other)
{
	Point temp;
	temp.x = x - other.x;
	temp.y = y - other.y;
	return (temp);
}

// Grid class
Grid::Grid ()
{
	width = 20;
	height = 20;
}

Grid::Grid (int size)
{
	width = size;
	height = size;
}

Grid::Grid (int Width, int Height)
{
	width = Width;
	height = Height;
}