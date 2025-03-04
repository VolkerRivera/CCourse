#include "point.h"
#include <string>

std::string Point::toString() const
{
    return "Point(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

std::istream& operator>>(std::istream& is, Point& p)
{
    is >> p.x >> p.y;
    return is;
}

nlohmann::json Point::serialize() const{
    return nlohmann::json{
        {"x", x},
        {"y", y}
    };
}

Point Point::deserialize(const nlohmann::json& j){
    return Point(
        j.at("x").get<int>(),
        j.at("y").get<int>()
    );
}