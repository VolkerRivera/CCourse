#include "toolbar.h"

void Toolbar::registerShape(ShapeType type, createShapefn factory)
{
    shapeRegistry[type] = factory;
}

std::unique_ptr<Shape> Toolbar::createShape(ShapeType type, Point p1, Point p2, Color color, int id)
{
    auto it = shapeRegistry.find(type);
    if (it != shapeRegistry.end())
    {
        return it->second(p1, p2, color, id);
    }
    return nullptr;
}

std::unordered_map<ShapeType, createShapefn> Toolbar::getShapesMap()
{
    return shapeRegistry;
}
