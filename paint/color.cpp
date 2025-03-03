#include "color.h"
#include <string>

std::string Color::toString() const
{
    return "RGB(" + std::to_string(static_cast<int>(red)) + ", " +
           std::to_string(static_cast<int>(green)) + ", " +
           std::to_string(static_cast<int>(blue)) + ")";
}

std::istream& operator>>(std::istream& is, Color& c)
{
    int r, g, b;
    is >> r >> g >> b;
    c = Color(static_cast<Color::byte>(r), static_cast<Color::byte>(g), static_cast<Color::byte>(b));
    return is; 
}
