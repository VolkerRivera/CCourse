#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>
#include "json.hpp"

class Color
{
public:
    using byte = unsigned char;
private:
    byte red;
    byte green;
    byte blue;
public:
    Color() = default;
    Color(byte r, byte g, byte b) : red(r), green(g), blue(b) {}

    byte getRed() const { return red; }
    byte getGreen() const { return green; }
    byte getBlue() const { return blue; }

    std::string toString() const;

    friend std::istream& operator>>(std::istream& is, Color& c);

    nlohmann::json serialize() const;
 
    static Color deserialize(const nlohmann::json& j);
};

#endif // COLOR_H
