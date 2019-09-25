#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"
class Rhombus : public Shape
{
	int d;
public:
	Rhombus(int, string = "Diamond", string = "A parallelogram with equal sides");

	virtual double geoArea() const override;
	virtual double geoPerimeter() const override;
	virtual int screenArea() const override;
	virtual int screenPerimeter() const override;
	virtual int boundingBoxHeight() const override;
	virtual int boundingBoxWidth() const override;

	virtual string getShapeName() const override;

	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;
};

#endif;
