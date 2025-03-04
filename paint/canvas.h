#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <memory>
#include "shape.h"
#include <algorithm>
#include <iostream>

class Canvas
{
private:
    std::vector<std::unique_ptr<Shape>> shapes;
public:
    void add(std::unique_ptr<Shape> shape);
    void remove(int id);
    void move(int id, Point new_p1, Point new_p2);
    void list();
    void export_to_file();
};

#endif // CANVAS_H
