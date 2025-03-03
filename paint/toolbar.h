#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <unordered_map>
#include <memory>
#include "shape.h"

class Toolbar
{
private:
    std::unordered_map<ShapeType, createShapefn> shapeRegistry;
public:
    void registerShape(ShapeType type, createShapefn factory);
    std::unique_ptr<Shape> createShape(ShapeType type, Point p1, Point p2, Color color, int id);
    std::unordered_map<ShapeType, createShapefn> getShapesMap();
};

#endif // TOOLBAR_H
