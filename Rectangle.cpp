#include "Rectangle.h"

Rectangle::Rectangle(int width, int height, string name, string description) 
	: Shape (name, description), width {width}, height {height}
{}

double Rectangle::geoArea() const
{
	return ((double)height) * width;
}

double Rectangle::geoPerimeter() const
{
	return 2 * ((double)height + width);
}

int Rectangle::screenArea() const
{
	return height * width;
}

int Rectangle::screenPerimeter() const
{
	return 2 * (height + width) - 4;
}

int Rectangle::boundingBoxHeight() const
{
	return height;
}

int Rectangle::boundingBoxWidth() const
{
	return width;
}

string Rectangle::getShapeName() const
{
	return "Rectangle";
}

Grid Rectangle::draw(char fChar, char bChar) const
{
	Grid matrix (boundingBoxHeight(), vector<char> (boundingBoxWidth()) );

	for (int i = 0; i < boundingBoxHeight(); i++)
	{
		for (int j = 0; j < boundingBoxWidth(); j++)
		{
			matrix[i][j] = fChar;
		}
	}
	return matrix;
}


