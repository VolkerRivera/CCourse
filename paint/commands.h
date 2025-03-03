#ifndef COMMANDS_H
#define COMMANDS_H

#include <memory>
#include "canvas.h"
#include "shape.h"
#include "point.h"
#include <iostream>

// Comando para crear un shape.
class CommandCreate
{
private:
    Canvas &receiver;
    std::unique_ptr<Shape> shape;
public:
    CommandCreate(Canvas &canvas, std::unique_ptr<Shape> shape);
    void run();
};

// Comando para listar shapes.
class CommandList
{
private:
    Canvas &receiver;
public:
    CommandList(Canvas &canvas);
    void run();
};

// Comando para remover un shape por id.
class CommandRemove
{
private:
    Canvas &receiver;
    int id;
public:
    CommandRemove(Canvas &canvas, int id);
    void run();
};

// Comando para mover un shape.
class CommandMove
{
private:
    Canvas &receiver;
    int id;
public:
    CommandMove(Canvas &canvas, int id);
    void run();
};

#endif // COMMANDS_H
