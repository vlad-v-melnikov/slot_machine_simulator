#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
	int height;
	int width;
public:
	Rectangle(int, int, string = "Four-sided", string = "Four right angles");
	
	virtual double geoArea() const override;
	virtual double geoPerimeter() const override;
	virtual int screenArea() const override;
	virtual int screenPerimeter() const override;
	virtual int boundingBoxHeight() const override;
	virtual int boundingBoxWidth() const override;

	virtual string getShapeName() const override;

	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;
};


#endif