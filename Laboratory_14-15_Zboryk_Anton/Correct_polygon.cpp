#include "Correct_polygon.h"
#include <corecrt_math_defines.h>
#include <cmath>
#include <stdexcept>

CorrectPolygon::CorrectPolygon(int sides, double length){
    if (sides < 5 || sides > 8) {
        throw std::invalid_argument("Кількість сторін повинна бути від 5 до 8.");
    }
    this->sidesCount = sides;
    this->sideLength = length;
}

std::string CorrectPolygon::getName() const {
    return "Правильний " + std::to_string(sidesCount) + "-кутник";
}

double CorrectPolygon::getArea() const {
    return (sidesCount * std::pow(sideLength, 2)) / (4 * std::tan(M_PI / sidesCount));
}

double CorrectPolygon::getPerimeter() const { return sidesCount * sideLength; }
// Зв'язок "описані/вписані": створює об'єкт колу
Circle* CorrectPolygon::createCircumscribedCircle() const {
    double radius = sideLength / (2 * std::sin(M_PI / sidesCount));
    return new Circle(radius);
}

Circle* CorrectPolygon::createInscribedCircle() const {
    double radius = sideLength / (2 * std::tan(M_PI / sidesCount));
    return new Circle(radius);
}