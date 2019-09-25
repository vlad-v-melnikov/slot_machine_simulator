#include "RightTriangle.h"

RightTriangle::RightTriangle(int b, string name, string description)
	: Triangle (name, description), b { b }, h { b }
{}

double RightTriangle::geoArea() const
{
	return ((double)h * b) / 2;
}

double RightTriangle::geoPerimeter() const
{
	return (2 + sqrt(2)) * (double)h;
}

int RightTriangle::screenArea() const
{
	return h * (h + 1) / 2;
}

int RightTriangle::screenPerimeter() const
{
	return 3 * (h - 1);
}

int RightTriangle::boundingBoxHeight() const
{
	return h;
}

int RightTriangle::boundingBoxWidth() const
{
	return b;
}

string RightTriangle::getShapeName() const
{
	return "Right triangle";
}

Grid RightTriangle::draw(char fChar, char bChar) const
{
	Grid matrix(boundingBoxHeight(), vector<char>(boundingBoxWidth()));
	int start = 0; //"top" tip
	int fill = 0; //increases by 1 at each iteration

	for (int i = 0; i < boundingBoxHeight(); i++)
	{
		for (int j = 0; j < boundingBoxWidth(); j++)
		{
			if (j <= start + fill)
			{
				matrix[i][j] = fChar;
			}
			else
			{
				matrix[i][j] = bChar;
			}
		}
		fill += 1;
	}
	return matrix;
}
