#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>

class Point
{
private:
    int x;
    int y;
public:
    Point() = default;
    Point(int x, int y) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    std::string toString() const;

    friend std::istream& operator>>(std::istream& is, Point& p);
};

#endif // POINT_H
