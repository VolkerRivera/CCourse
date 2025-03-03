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
