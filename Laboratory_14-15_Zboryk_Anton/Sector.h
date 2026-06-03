#pragma once
#include "Figure.h"
#include <corecrt_math_defines.h>
#include <iostream>

class Sector : public Figure {
private:
    double radius;
    double angleInDegrees;
public:
    Sector(double r, double angle);

    std::string getName() const override;

    double getArea() const override;

    double getPerimeter() const override;
};

