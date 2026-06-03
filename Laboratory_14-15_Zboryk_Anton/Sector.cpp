#include "Sector.h"
#include <corecrt_math_defines.h>
#include <cmath>

Sector::Sector(double r, double angle) : radius(r), angleInDegrees(angle) {}

std::string Sector::getName() const { return "Сектор"; }

double Sector::getArea() const {
    return M_PI * std::pow(radius, 2) * (angleInDegrees / 360.0);
}

double Sector::getPerimeter() const {
    double arcLength = 2 * M_PI * radius * (angleInDegrees / 360.0);
    return arcLength + (2 * radius);
}