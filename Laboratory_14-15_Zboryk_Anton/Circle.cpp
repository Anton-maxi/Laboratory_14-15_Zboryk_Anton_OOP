#include "Circle.h"
#include <corecrt_math_defines.h>

Circle::Circle(double r) {
	this->radius = r;
}

std::string Circle::getName() const { return "Коло"; }
double Circle::getArea() const { return M_PI * radius * radius; }
double Circle::getPerimeter() const { return 2 * M_PI * radius; }
double Circle::getRadius() const { return radius; }