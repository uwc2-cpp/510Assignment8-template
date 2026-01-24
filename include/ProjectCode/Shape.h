#pragma once

#include <ostream>

class Shape
{
public:
    Shape() = default;
    Shape(const Shape& src) = default;
    Shape(Shape&& src) = default;
    Shape& operator=(const Shape& rhs) = default;
    Shape& operator=(Shape&& rhs) = default;

    virtual ~Shape() = default;

    virtual void draw() const = 0;

    virtual void stream(std::ostream& os) const = 0;
};

// Use the virtual stream operator of the shape. This way a single override of operator<<() for shape
// correctly streams all subclasses
inline std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    shape.stream(os);
    return os;
}