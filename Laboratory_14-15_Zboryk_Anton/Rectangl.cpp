#include "Rectangl.h"
#include <string>
#include <memory>


Rectangl::Rectangl(double w, double h){
	this->width = w;
	this->height = h;
}

std::string Rectangl::getName() const { return "Прямокутник"; }
double Rectangl::getArea() const { return width * height; }
double Rectangl::getPerimeter() const { return 2 * (width + height); }