#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;
using Grid = vector<vector<char>>;

//abstract class for the root of the shape tree

class Shape
{
private:
	static int id_counter;

	int id;
	string name;
	string description;

public:
	Shape(string = "Default shape name", string = "Default shape description");

	int getId() const;
	string getName() const;
	string getDescription() const;

	void setName(string);
	void setDescription(string);
	virtual double geoArea() const = 0;
	virtual double geoPerimeter() const = 0;
	virtual int screenArea() const = 0;
	virtual int screenPerimeter() const = 0;
	virtual int boundingBoxHeight() const = 0;
	virtual int boundingBoxWidth() const = 0;
	virtual string toString() const;
	virtual string getShapeName() const = 0;

	virtual Grid draw(char fChar = '*', char bChar = ' ') const = 0;
};

ostream& operator<< (ostream&, const Shape&);

#endif
