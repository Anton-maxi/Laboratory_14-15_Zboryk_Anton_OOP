#pragma once

class Point2D
{
private:
    double X;
    double Y;
public:
    double GetX() const;
    double GetY() const;

    Point2D();
    Point2D(double x, double y);

    double DistanceTo(Point2D other) const;
};




