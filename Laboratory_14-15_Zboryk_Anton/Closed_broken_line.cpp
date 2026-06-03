#include "Closed_broken_line.h"
#include "Point2D.h"
#include <vector>
#include <stdexcept>

Closed_broken_line::Closed_broken_line(const std::vector<Point2D>& pts) {
    if (pts.size() < 3) {
        throw std::invalid_argument("Для замкненої ламаної потрібно мінімум 3 точки.");
    }
    this->points = pts;
}

std::string Closed_broken_line::getName() const { return "Замкнена ламана"; }

double Closed_broken_line::getPerimeter() const {
    double perimeter = 0;
    size_t n = points.size();
    for (size_t i = 0; i < n; ++i) {
        perimeter += points[i].DistanceTo(points[(i + 1) % n]);
    }
    return perimeter;
}

// Площа за формулою Гаусса
double Closed_broken_line::getArea() const {
    double area = 0.0;
    size_t n = points.size();
    size_t j = n - 1;

    for (size_t i = 0; i < n; ++i) {
        area += (points[j].GetX() + points[i].GetX()) * (points[j].GetY() - points[i].GetY());
        j = i;
    }
    return std::abs(area / 2.0);
}