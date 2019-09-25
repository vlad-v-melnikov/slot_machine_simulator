#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"
#include "Shape.h"
class RightTriangle : public Triangle
{
	int b;
	int h;
public:
	RightTriangle(int, string = "Right triangle", string = "One right and two acute angles");

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

