#pragma once
#include "Figure.h"
#include "Point2D.h"
#include <vector>
#include <stdexcept>

class Closed_broken_line : public Figure {
private:
    std::vector<Point2D> points;
public:
    Closed_broken_line(const std::vector<Point2D>& pts);

    std::string getName() const override;

    double getPerimeter() const override;

    // Площа за формулою Гаусса
    double getArea() const override;
};

