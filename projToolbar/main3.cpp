#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <memory>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>
 
 
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
    int id;
 
protected:
    Shape(Point start, Point end, Color color, int id) : start(start), end(end), color(color), id(id) {}
 
public:
    void setStart(Point a){start = a;}
    void setEnd(Point b){end = b;}
    Point getStart() const { return start; }
    Point getEnd() const { return end; }
    Color getColor() const { return color; }
    int getId() const {return id; }
    virtual std::string toString() const
    {
        return "Shape from " + start.toString() + " to " + end.toString() + " with color " + color.toString() + " and ID #" + std::to_string(id);
    }
};
 
using createShapefn = std::function<std::unique_ptr<Shape>(Point, Point, Color, int)>;
 
enum class ShapeType
{
    RECTANGLE,
    CIRCLE
};
 
class Rectangle : public Shape
{
protected:
    Rectangle(Point start, Point end, Color color, int id) : Shape(start, end, color, id) {}
 
public:
    std::string toString() const override
    {
        return "Rectangle: " + Shape::toString();
    }
 
    static std::unique_ptr<Shape> create(Point p1, Point p2, Color color, int id)
    {
        return std::unique_ptr<Rectangle>(new Rectangle(p1, p2, color, id));
    }
};
 
class Circle : public Shape
{
 
protected:
    Circle(Point center, Point radiusPoint, Color color, int id) : Shape(center, radiusPoint, color, id) {}
 
public:
    std::string toString() const override
    {
        return "Circle: " + Shape::toString();
    }
    static std::unique_ptr<Shape> create(Point p1, Point p2, Color color, int id)
    {
        return std::unique_ptr<Circle>(new Circle(p1, p2, color, id));
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
    std::unique_ptr<Shape> createShape(ShapeType type, Point p1, Point p2, Color color, int id)
    {
        auto it = shapeRegistry.find(type);
        if (it != shapeRegistry.end())
        {
            return it->second(p1, p2, color, id);
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

std::unique_ptr<Shape>shapeInterface(Toolbar toolbar, int identificador){
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
    return toolbar.createShape(shape, p0, p1, color, identificador++);
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


class Canvas
{
private:
    std::vector<std::unique_ptr<Shape>> shapes; // array de Shape
 
public:
    void add(std::unique_ptr<Shape> shape)
    {      
       
        shapes.push_back(std::move(shape));                  
    }

    void remove(int id){
        /* remove_if reordena elementos en un rango de tal manera que todos los elementos que cumplen con la condición lambda se mueven al final del rango
        Como tal no elimina el elemento, sino que reordena los elementos y devuelve un iterador que apunta al nuevo final del rango de elementos
        válidos. Los elementos a eliminar se encuentran después de este iterador
        */
        auto newEnd = std::remove_if(shapes.begin(), shapes.end(), [id](const std::unique_ptr<Shape>& shape){
            return shape->getId() == id;
        });
        shapes.erase(newEnd, shapes.end());
        std::cout << "Shade with id: " << std::to_string(id) << " was removed." << std::endl;
    }

    void move(int id, Point new_p1, Point new_p2){
        for(const auto& shape : shapes){ //shape es la referencia a cada shape, por lo que se actualizara correctamente
            if(shape->getId() == id){
                shape->setStart(new_p1);
                shape->setEnd(new_p2);
                return;
            }
        }
        std::cout << "No hay ninguna figura con ese ID." << std::endl;
    }

    void list()
    {
        for (const auto &shape : shapes)
        {
            std::cout << shape->toString() << std::endl;
        }
    }
};
class CommandCreate
{
private:
    Canvas &receiver;
    std::unique_ptr<Shape> shape;
 
public:
    CommandCreate(Canvas &canvas, std::unique_ptr<Shape> shape)
        : receiver(canvas), shape(std::move(shape))
    {
    }
    void run()
    {
        receiver.add(std::move(shape));
    }
};
 
class CommandList
{
private:
    Canvas &receiver;
   
public:
    CommandList(Canvas &canvas) : receiver(canvas)
    {
    }
    void run()
    {
        receiver.list();
    }
};

class CommandRemove
{
    private:
        Canvas &receiver;
        int id;
    public:
        CommandRemove(Canvas &canvas, int id) : receiver(canvas), id(id){}
        void run(){
            receiver.remove(id);
        }
};

class CommandMove
{
    private:
        Canvas &receiver;
        int id;
    public:
        CommandMove(Canvas &canvas, int id) : receiver(canvas), id(id){}
        void run(){
            Point new_start;
            std::cout << "introduzca el nuevo punto de inicio:" << std::endl;
            std::cin >> new_start;
            std::cout << new_start.toString() << std::endl;
 
            Point new_end;
            std::cout << "introduzca el nuevo punto final:" << std::endl;
            std::cin >> new_end;
            std::cout << new_end.toString() << std::endl;

            receiver.move(id, new_start, new_end);
        }
};
 
class App
{
private:
    Toolbar &toolbar;
    Canvas &canvas;
 
public:
    App(Toolbar &toolbar, Canvas &canvas) : toolbar(toolbar), canvas(canvas)
    {
    }
    void run()
    {
        int opcion;
        int id = 0;

        std::string cmd;
        do
        {
            showMenu();
            std::cin >> opcion;
            int id_rmv;
 
            switch (opcion)
            {
            case 1:
            {
               
                std::cout << "Creando un shape..." << std::endl;
                CommandCreate create(canvas, shapeInterface(toolbar, id));
                create.run();   
                id++;             
                break;
            }
            case 2:
            {
                do{
                    clear();
                    std::cout << "Listando todos los shapes...\n" << std::endl;
                    CommandList list(canvas);
                    list.run();
                    std::cout << "\nVolver al menu principal? (y/other)" << std::endl;
                    std::cin >> cmd;
                }while(cmd != "y");          
                break;
            }
 
            case 3:
            {
                std::cout << "Introduzca el ID de la shape que desea eliminar: " << std::endl;
                std::cin >> id_rmv;
                CommandRemove remove(canvas, id_rmv);
                remove.run();
                std::cout << "Eliminando un shape por ID..." << std::endl;
                break;
            }
            case 4:
            {
                int id_mv;
                std::cout << "Introduzca el ID del shape que desea mover: " << std::endl;
                std::cin >> id_mv;
                CommandMove move(canvas, id_mv);
                move.run();
                std::cout << "Moviendo un shape a un punto..." << std::endl;
                break;
            }
            case 5:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            }
        } while (opcion != 5);
       
    }
};
 
int main()
{
    Toolbar toolbar;
    toolbar.registerShape(ShapeType::CIRCLE, Circle::create);
    toolbar.registerShape(ShapeType::RECTANGLE, Rectangle::create);
    Canvas canvas;
    App app(toolbar, canvas);
    app.run();
    return 0;
}