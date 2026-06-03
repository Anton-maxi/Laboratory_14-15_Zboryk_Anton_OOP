#pragma once
#include "Figure.h"
#include <iostream>
#include <corecrt_math_defines.h>
#include "Circle.h"

class CorrectPolygon : public Figure {
private:
    int sidesCount;
    double sideLength;
public:
    CorrectPolygon(int sides, double length);

    std::string getName() const override;

    double getArea() const override;

    double getPerimeter() const override;

    // Зв'язок "описані/вписані": створює об'єкт колу
    std::unique_ptr<Circle> createCircumscribedCircle() const;

    std::unique_ptr<Circle> createInscribedCircle() const;
};

