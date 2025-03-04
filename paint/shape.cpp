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

nlohmann::json Shape::serialize() const{
    nlohmann::json j;
    j["start"] = start.serialize();
    j["end"] = end.serialize();
    j["color"] = color.serialize();
    j["id"] = id;

    return j;
}

std::unique_ptr<Shape> Shape::deserialize(const nlohmann::json& j){
    if(!j.contains("type")){
        throw std::runtime_error("El JSON no contiene el campo 'type' para identificar la forma...");
    }
    std::string type = j["type"].get<std::string>();
    // Se recuperan los atributos comunes
    Point start = Point::deserialize(j["start"]);
    Point end = Point::deserialize(j["end"]);
    Color color = Color::deserialize(j["color"]); // Se asume que Color tiene deserialize
    int id = j["id"].get<int>();

    if (type == "RECTANGLE" || "rectangle") {
        return Rectangle::create(start, end, color, id);
    }
    else if (type == "CIRCLE" || "circle") {
        return Circle::create(start, end, color, id);
    }
    else {
        throw std::runtime_error("Tipo de Shape desconocido: " + type);
    }
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
