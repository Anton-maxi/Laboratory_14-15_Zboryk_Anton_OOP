#include "Rectangl.h"
#include <cmath>
#include <stdexcept>


Rectangl::Rectangl(double w, double h){
	this->width = w;
	this->height = h;
}

std::string Rectangl::getName() const { return "Прямокутник"; }
double Rectangl::getArea() const { return width * height; }
double Rectangl::getPerimeter() const { return 2 * (width + height); }

// Зв'язок "описані/вписані": створює об'єкт колу
Circle* Rectangl::createCircumscribedCircle() const {
    double radius = std::sqrt(width * width + height * height) / 2;
    return new Circle(radius);
}

Circle* Rectangl::createInscribedCircle() const {
    if (width != height) {
        throw std::logic_error("Вписане коло можливе лише для квадрату.");
	}
    double radius = width / 2;
    return new Circle(radius);
}