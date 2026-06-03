#pragma once
#include <string>

class Figure
{
public:
    virtual ~Figure() = default;
    virtual std::string getName() const = 0;
    virtual double getArea() const = 0;      // σ κβ. μμ
    virtual double getPerimeter() const = 0; // σ μμ
};

