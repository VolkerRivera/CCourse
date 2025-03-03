#ifndef UTIL_H
#define UTIL_H

#include <string>
#include "toolbar.h"

// Muestra el menú principal.
void showMenu();

// Limpia la pantalla.
void clear();

// Función de interfaz para crear un shape.
std::unique_ptr<Shape> shapeInterface(Toolbar toolbar, int identificador);

// Muestra los shapes registrados en el toolbar.
void showInterface(Toolbar toolbar);

// Función auxiliar que convierte ShapeType a string.
std::string shapeToString(ShapeType shape);

#endif // UTIL_H
