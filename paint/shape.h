#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <memory>
#include <functional>
#include "point.h"
#include "color.h"

// Clase base Shape
class Shape
{
private:
    Point start;
    Point end;
    Color color;
    int id;

protected:
    Shape(Point start, Point end, Color color, int id)
        : start(start), end(end), color(color), id(id) {}

public:
    void setStart(Point a);
    void setEnd(Point b);
    Point getStart() const;
    Point getEnd() const;
    Color getColor() const;
    int getId() const;

    virtual std::string toString() const;
};

using createShapefn = std::function<std::unique_ptr<Shape>(Point, Point, Color, int)>;

enum class ShapeType
{
    RECTANGLE,
    CIRCLE
};

// Clase Rectangle derivada de Shape
class Rectangle : public Shape
{
protected:
    Rectangle(Point start, Point end, Color color, int id)
        : Shape(start, end, color, id) {}
public:
    std::string toString() const override;
    static std::unique_ptr<Shape> create(Point p1, Point p2, Color color, int id);
};

// Clase Circle derivada de Shape
class Circle : public Shape
{
protected:
    Circle(Point center, Point radiusPoint, Color color, int id)
        : Shape(center, radiusPoint, color, id) {}
public:
    std::string toString() const override;
    static std::unique_ptr<Shape> create(Point p1, Point p2, Color color, int id);
};

#endif // SHAPE_H
