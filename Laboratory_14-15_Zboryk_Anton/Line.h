#pragma once
#include "Figure.h"
#include "Point2D.h"
#include <string>

class Line : public Figure
{
private:
    Point2D Start;
	Point2D End;
public:

	Point2D GetStart() const;
	Point2D GetEnd() const;
	void SetStart(Point2D start);
	void SetEnd(Point2D end);
	std::string getName() const override;

    Line(const Point2D& start, const Point2D& end);

	double getArea() const override;// Лінія не має площі

	double getPerimeter() const override;

};

