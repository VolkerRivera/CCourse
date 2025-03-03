#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <memory>
#include <thread>
#include <chrono>
 
 
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
 
    std::string toString() const
    {
        return "Point(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
    friend std::istream& operator>>(std::istream& is, Point& p)
    {
        is >> p.x >> p.y;
        return is;
    }
};


 
class Color
{
private:
    using byte = unsigned char;
    byte red;
    byte green;
    byte blue;
 
public:
    Color() = default;
    Color(byte r, byte g, byte b) : red(r), green(g), blue(b) {}
 
    byte getRed() const { return red; }
    byte getGreen() const { return green; }
    byte getBlue() const { return blue; }
 
    std::string toString() const
    {
        return "RGB(" + std::to_string(static_cast<int>(red)) + ", " +
               std::to_string(static_cast<int>(green)) + ", " +
               std::to_string(static_cast<int>(blue)) + ")";
    }
    friend std::istream& operator>>(std::istream& is, Color& c){
        int r, g, b;
        is >> r >> g >> b;
        c = Color(static_cast<Color::byte>(r), static_cast<Color::byte>(g), static_cast<Color::byte>(b));
        return is; 
    }
};

 
class Shape
{
private:
    Point start;
    Point end;
    Color color;
 
protected:
    Shape(Point start, Point end, Color color) : start(start), end(end), color(color) {}
 
public:
    Point getStart() const { return start; }
    Point getEnd() const { return end; }
    Color getColor() const { return color; }
    virtual std::string toString() const
    {
        return "Shape from " + start.toString() + " to " + end.toString() + " with color " + color.toString();
    }
};
 
using createShapefn = std::function<std::unique_ptr<Shape>(Point, Point, Color)>;
 
enum class ShapeType
{
    RECTANGLE,
    CIRCLE
};
 
class Rectangle : public Shape
{
protected:
    Rectangle(Point start, Point end, Color color) : Shape(start, end, color) {}
 
public:
    std::string toString() const override
    {
        return "Rectangle: " + Shape::toString();
    }
 
    static std::unique_ptr<Shape> create(Point p1, Point p2, Color color)
    {
        return std::unique_ptr<Rectangle>(new Rectangle(p1, p2, color));
    }
};
 
class Circle : public Shape
{
 
protected:
    Circle(Point center, Point radiusPoint, Color color) : Shape(center, radiusPoint, color) {}
 
public:
    std::string toString() const override
    {
        return "Circle: " + Shape::toString();
    }
    static std::unique_ptr<Shape> create(Point p1, Point p2, Color color)
    {
        return std::unique_ptr<Circle>(new Circle(p1, p2, color));
    }
};
 
class Toolbar
{
private:
    std::unordered_map<ShapeType, createShapefn> shapeRegistry;
 
public:
    void registerShape(ShapeType type, createShapefn factory)
    {
        shapeRegistry[type] = factory;
    }
    std::unique_ptr<Shape> createShape(ShapeType type, Point p1, Point p2, Color color)
    {
        auto it = shapeRegistry.find(type);
        if (it != shapeRegistry.end())
        {
            return it->second(p1, p2, color);
        }
        return nullptr;
    }
    std::unordered_map<ShapeType, createShapefn> getShapesMap(){return shapeRegistry;}

};

std::string shapeToString(ShapeType shape){
    switch(shape){
        case ShapeType::RECTANGLE:
            return "RECTANGLE";
        case ShapeType::CIRCLE:
            return "CIRCLE";
        default:
            return "UNKNOWN";
    }
}

std::unique_ptr<Shape>shapeInterface(Toolbar toolbar){
    Point p0;
    std::cout << "introduzca el punto de inicio:" << std::endl;
    std::cin >> p0;
    std::cout << p0.toString() << std::endl;
 
    Point p1;
    std::cout << "introduzca el punto final:" << std::endl;
    std::cin >> p1;
    std::cout << p1.toString() << std::endl;
 
    Color color;
    std::cout << "introduzca el color:" << std::endl;
    std::cin >> color;
    std::cout << color.toString() << std::endl;
 
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
        std::cout << "Entrada inválida." << std::endl;
    }
    return toolbar.createShape(shape, p0, p1, color);
}

void showInterface(Toolbar toolbar) {
    auto map = toolbar.getShapesMap();
    std::cout << "Registered shapes:" << std::endl;
    for (const auto& entry : map) {
        switch (entry.first) {
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

void clear(){ // comando clear en la terminal
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

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

class App
{
private:
    Toolbar toolbar;
 
public:
    App(Toolbar toolbar) : toolbar(toolbar)
    {
    }
    void run()
    {
        int opcion;
        std::string cmd;
        do
        {
            showMenu();
            std::cin >> opcion;
 
            switch (opcion)
            {
            case 1:
                std::cout << "Creando un shape..." << std::endl;
                clear();
                shapeInterface(toolbar);
                break;
            case 2:
                std::cout << "Listando todos los shapes..." << std::endl;
                do{
                    clear();
                    showInterface(toolbar);
                    std::cout << "Desea volver al menu principal? (y/other)" << std::endl;
                    std::cin >> cmd;
                }while(cmd != "y");
                break;
            case 3:
                std::cout << "Eliminando un shape por ID..." << std::endl;
                break;
            case 4:
                std::cout << "Moviendo un shape a un punto..." << std::endl;
                break;
            case 5:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            }
            
        } while (opcion != 5);
        clear();
    }
};

int main()
{
    Toolbar toolbar;
    toolbar.registerShape(ShapeType::CIRCLE, Circle::create);
    toolbar.registerShape(ShapeType::RECTANGLE, Rectangle::create);
 
    App app(toolbar);
    app.run();
     
   
    return 0;
}