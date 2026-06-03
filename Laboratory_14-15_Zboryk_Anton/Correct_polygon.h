#pragma once
#include "Figure.h"
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
    Circle* createCircumscribedCircle() const;
    Circle* createInscribedCircle() const;
};

