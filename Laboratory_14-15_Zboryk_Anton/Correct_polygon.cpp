#include "Correct_polygon.h"

CorrectPolygon::CorrectPolygon(int sides, double length) : sidesCount(sides), sideLength(length) {
    if (sides < 5 || sides > 8) {
        throw std::invalid_argument("Кількість сторін повинна бути від 5 до 8.");
    }
}

std::string CorrectPolygon::getName() const {
    return "Правильний " + std::to_string(sidesCount) + "-кутник";
}

double CorrectPolygon::getArea() const {
    return (sidesCount * std::pow(sideLength, 2)) / (4 * std::tan(M_PI / sidesCount));
}

double CorrectPolygon::getPerimeter() const { return sidesCount * sideLength; }
// Зв'язок "описані/вписані": створює об'єкт колу
std::unique_ptr<Circle> CorrectPolygon::createCircumscribedCircle() const {
    double radius = sideLength / (2 * std::sin(M_PI / sidesCount));
    return std::make_unique<Circle>(radius);
}

std::unique_ptr<Circle> CorrectPolygon::createInscribedCircle() const {
    double radius = sideLength / (2 * std::tan(M_PI / sidesCount));
    return std::make_unique<Circle>(radius);
}