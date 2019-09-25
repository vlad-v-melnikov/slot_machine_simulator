#include "AcuteTriangle.h"

AcuteTriangle::AcuteTriangle(int b, string name, string description)
	: Triangle (name, description)
{
	if (b % 2 == 0)
		this->b = b + 1;
	else
		this->b = b;

	h = (b + 1) / 2;
}

double AcuteTriangle::geoArea() const
{
	return ((double)h * b) / 2;
}

double AcuteTriangle::geoPerimeter() const
{
	return (double)b + 2 * sqrt(0.25 * b * b + (double)h * h);
}

int AcuteTriangle::screenArea() const
{
	return h * h;
}

int AcuteTriangle::screenPerimeter() const
{
	return 4 * (h - 1);
}

int AcuteTriangle::boundingBoxHeight() const
{
	return h;
}

int AcuteTriangle::boundingBoxWidth() const
{
	return b;
}

string AcuteTriangle::getShapeName() const
{
	return "Acute triangle";
}

Grid AcuteTriangle::draw(char fChar, char bChar) const
{
	Grid matrix(boundingBoxHeight(), vector<char>(boundingBoxWidth()));
	int start = b / 2; //"top" tip
	int fill = 0; //increases by 1 at each iteration

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
		fill += 1;
	}
	return matrix;
}
