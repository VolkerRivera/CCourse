#include "canvas.h"
#include "GestorFichero.h"
#include "util.h"
#include <fstream>
#include <iostream>

void Canvas::add(std::unique_ptr<Shape> shape)
{
    shapes.push_back(std::move(shape));
}

void Canvas::remove(int id)
{
    auto newEnd = std::remove_if(shapes.begin(), shapes.end(),
        [id](const std::unique_ptr<Shape>& shape) {
            return shape->getId() == id;
        }
    );
    shapes.erase(newEnd, shapes.end());
    std::cout << "Shape with id: " << id << " was removed." << std::endl;
}

void Canvas::move(int id, Point new_p1, Point new_p2)
{
    for (auto& shape : shapes)
    {
        if(shape->getId() == id)
        {
            shape->setStart(new_p1);
            shape->setEnd(new_p2);
            return;
        }
    }
    std::cout << "No shape found with id: " << id << std::endl;
}

void Canvas::list()
{
    for (const auto &shape : shapes)
    {
        std::cout << shape->toString() << std::endl;
    }
}

void Canvas::export_to_file(){
    std::cout << "im here" << std::endl; 
    GestorFichero fichero = GestorFichero("OutputFile.json");
    std::string lines;
    for(const auto&shape : shapes)
    {
        lines = lines + shape->serialize().dump(4) + ",";
        std::cout << lines << std::endl;
    }
    fichero.escribir(lines, false);

}
