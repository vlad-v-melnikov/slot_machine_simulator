#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H

#include "Triangle.h"
class AcuteTriangle : public Triangle
{
	int b;
	int h;
public:
	AcuteTriangle(int, string = "Acute triangle", string = "All acute angles");

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