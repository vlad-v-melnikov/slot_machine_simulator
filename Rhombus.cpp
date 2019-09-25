#include "Rhombus.h"

Rhombus::Rhombus(int d, string name, string description)
	: Shape (name, description), d {d}
{
	if (this->d % 2 == 0) ++(this->d);
}

double Rhombus::geoArea() const
{
	return ((double)d*d)/2;
}

double Rhombus::geoPerimeter() const
{
	return 2 * (sqrt(2)) * d;
}

int Rhombus::screenArea() const
{
	int n = d / 2;
	return 2 * n * (n + 1) + 1;
}

int Rhombus::screenPerimeter() const
{
	return 2 * (d - 1);
}

int Rhombus::boundingBoxHeight() const
{
	return d;
}

int Rhombus::boundingBoxWidth() const
{
	return d;
}

string Rhombus::getShapeName() const
{
	return "Diamond";
}

Grid Rhombus::draw(char fChar, char bChar) const
{
	Grid matrix(boundingBoxHeight(), vector<char>(boundingBoxWidth()));
	int start = d / 2; //"top" tip
	int fill = 0; //increases by 1 until == d, then descreases by 1 - fill distance from start

	for (int i = 0; i < boundingBoxHeight(); i++)
	{
		for (int j = 0; j < boundingBoxWidth(); j++)
		{
			if ((j >= start - fill) && (j <= start + fill))
			{
				matrix[i][j] = fChar;
			}
			else
			{
				matrix[i][j] = bChar;
			}
		}
		if (i < d / 2)
		{
			fill += 1;
		}
		else
		{
			fill -= 1;
		}
		
	}
	return matrix;
}
