#include "Line.h"
#include "Point2D.h"

Line::Line(const Point2D& start, const Point2D& end)
{
    Start = start;
    End = end;
}
Point2D Line::GetStart() const { return Start; }
Point2D Line::GetEnd() const { return End; }
void Line::SetStart(Point2D start) { Start = start; }
void Line::SetEnd(Point2D end) { End = end; }
std::string Line::getName() const { return "Лінія"; }

double Line::getArea() const { return 0; } // Лінія не має площі

double Line::getPerimeter() const { return Start.DistanceTo(End); }