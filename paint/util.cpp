#include "util.h"
#include "point.h"
#include "color.h"
#include "shape.h"
#include <iostream>
#include <cstdlib>

// Limpia la pantalla (compatible con Windows y Unix).
void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Muestra el menú de opciones.
void showMenu()
{
    clear();
    std::cout << "\n--- Menu Shapes ---" << std::endl;
    std::cout << "1. Crea el shape" << std::endl;
    std::cout << "2. Lista todos los shapes" << std::endl;
    std::cout << "3. Elimina el shape por id" << std::endl;
    std::cout << "4. Mueve el shape a un punto en concreto" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

// Convierte ShapeType a string.
std::string shapeToString(ShapeType shape)
{
    switch(shape)
    {
        case ShapeType::RECTANGLE:
            return "RECTANGLE";
        case ShapeType::CIRCLE:
            return "CIRCLE";
        default:
            return "UNKNOWN";
    }
}

// Muestra la interfaz de los shapes registrados en el toolbar.
void showInterface(Toolbar toolbar)
{
    auto map = toolbar.getShapesMap();
    std::cout << "Registered shapes:" << std::endl;
    for (const auto& entry : map)
    {
        switch (entry.first)
        {
            case ShapeType::RECTANGLE:
                std::cout << "Registered shape: RECTANGLE" << std::endl;
                break;
            case ShapeType::CIRCLE:
                std::cout << "Registered shape: CIRCLE" << std::endl;
                break;
            default:
                std::cout << "Unknown shape type" << std::endl;
                break;
        }
    }
    std::cout << "Total registered shapes: " << map.size() << std::endl;
}

// Interfaz para crear un shape: lee los datos y llama al toolbar para crear la figura.
std::unique_ptr<Shape> shapeInterface(Toolbar toolbar, int identificador)
{
    Point p0;
    std::cout << "Introduzca el punto de inicio:" << std::endl;
    std::cin >> p0;
    std::cout << "Punto de inicio: " << p0.toString() << std::endl;
 
    Point p1;
    std::cout << "Introduzca el punto final:" << std::endl;
    std::cin >> p1;
    std::cout << "Punto final: " << p1.toString() << std::endl;
 
    Color color;
    std::cout << "Introduzca el color (R G B):" << std::endl;
    std::cin >> color;
    std::cout << "Color: " << color.toString() << std::endl;
 
    int shapeInput;
    ShapeType shape;
    std::cout << "Introduzca el shape (0-rectangle, 1-circle):" << std::endl;
    std::cin >> shapeInput;
 
    if (shapeInput == 0 || shapeInput == 1)
    {
        shape = static_cast<ShapeType>(shapeInput);
        std::cout << "Shape: " << shapeToString(shape) << std::endl;
    }
    else
    {
        std::cout << "Entrada inválida. Se creará un RECTANGLE por defecto." << std::endl;
        shape = ShapeType::RECTANGLE;
    }
    return toolbar.createShape(shape, p0, p1, color, identificador);
}
