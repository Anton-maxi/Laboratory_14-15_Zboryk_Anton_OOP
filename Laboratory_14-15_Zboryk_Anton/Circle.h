#pragma once
#include "Figure.h"
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r);

    std::string getName() const override;
    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
};

