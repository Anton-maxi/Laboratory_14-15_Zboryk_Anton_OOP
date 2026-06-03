#pragma once
#include "Figure.h"
#include "Circle.h"
#include <string>
#include <memory>

class Rectangl : public Figure 
{
private:
    double width;
    double height;
public:
    Rectangl(double w, double h);

    std::string getName() const override;
    double getArea() const override;
    double getPerimeter() const override;
    // Зв'язок "описані/вписані": створює об'єкт колу
    Circle* createCircumscribedCircle() const;
    Circle* createInscribedCircle() const;
};

