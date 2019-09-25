#include <iomanip>
#include <sstream>
#include <typeinfo>

#include "Shape.h"

int Shape::id_counter = 0;

Shape::Shape(string name, string description) : name{ name }, description{ description }
{
	//generate a value for id
	id = ++id_counter;
}

int Shape::getId() const
{
	return id;
}

string Shape::getName() const
{
	return name;
}

string Shape::getDescription() const
{
	return description;
}

void Shape::setName(string name)
{
	this->name = name;
}

void Shape::setDescription(string description)
{
	this->description = description;
}

string Shape::toString() const
{
	stringstream outStream;
	
	outStream << "Shape Information\n-----------------\n";
	outStream << "id:\t\t" << this->getId() << "\n";
	outStream << "Shape name:\t" << this->getName() << "\n";
	outStream << "Description:\t" << this->getDescription() << "\n";
	outStream << "B. box width:\t" << this->boundingBoxWidth() << "\n";
	outStream << "B. box height:\t" << this->boundingBoxHeight() << "\n";
	outStream << "Scr area:\t" << this->screenArea() << "\n";
	outStream << "Geo area:\t" << fixed << setprecision(2) << this->geoArea() << "\n";
	outStream << "Scr perimeter:\t" << this->screenPerimeter() << "\n";
	outStream << "Geo perimeter:\t" << this->geoPerimeter() << "\n";
	outStream << "Static type:\t" << typeid(this).name() << "\n";
	outStream << "Dynamic type:\t" << typeid(*this).name() << "\n";

	return outStream.str();
}

ostream& operator<< (ostream& out, const Shape& shape)
{
	out << shape.toString();
	return out;
}