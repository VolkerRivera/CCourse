#include "shape.h"
#include <string>

// Métodos de Shape
void Shape::setStart(Point a) { start = a; }
void Shape::setEnd(Point b) { end = b; }
Point Shape::getStart() const { return start; }
Point Shape::getEnd() const { return end; }
Color Shape::getColor() const { return color; }
int Shape::getId() const { return id; }

std::string Shape::toString() const
{
    return "Shape from " + start.toString() +
           " to " + end.toString() +
           " with color " + color.toString() +
           " and ID #" + std::to_string(id);
}

// Métodos de Rectangle
std::string Rectangle::toString() const
{
    return "Rectangle: " + Shape::toString();
}

std::unique_ptr<Shape> Rectangle::create(Point p1, Point p2, Color color, int id)
{
    return std::unique_ptr<Rectangle>(new Rectangle(p1, p2, color, id));
}

// Métodos de Circle
std::string Circle::toString() const
{
    return "Circle: " + Shape::toString();
}

std::unique_ptr<Shape> Circle::create(Point p1, Point p2, Color color, int id)
{
    return std::unique_ptr<Circle>(new Circle(p1, p2, color, id));
}
