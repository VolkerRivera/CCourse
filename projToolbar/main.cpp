#include <iostream>
#include <string>
#include <sstream>

class Point {
    private:
        int x;
        int y;
    public:
        Point(int x, int y) : x(x), y(y){};
        int getX(){return x;}
        int getY(){return y;}
        ~ Point() = default;
        std::string toString() const {
            std::ostringstream oss;
            oss << "Point(" << x << ", " << y << ")";
            return oss.str();
        }
};

class Color {
    private:
        int red;
        int green;
        int blue;
    public:
        Color(int white, int black, int red, int green, int blue) : 
        red(red), green(green), blue(blue){};
        int getR(){return red;}
        int getG(){return green;}
        int getB(){return blue;}
        std::string toString() const {
            std::ostringstream oss;
            oss << "Color(Red: " << red << ", Green: " << green 
                << ", Blue: " << blue << ")";
            return oss.str();
        }
        ~ Color() = default;
};
class Shape {
    private:
        Point inicio;
        Point fin;
        Color color;
    public:
        Shape() = delete; 
        Point getInicio(){return inicio;}
        Point getFin(){return inicio;}
        Color getColor(){return color;}
        ~ Shape() = default;
    protected:
        Shape(Point inicio, Point fin, Color color) : inicio(inicio), fin(fin), color(color){} 
};
class Circle    : virtual public Shape {
    public:
        Circle(Point inicio, Point fin, Color color) : Shape(inicio, fin, color){};
        
        std::string toString() {
            std::ostringstream oss;
            oss << "Circle: " << "Inicio: " << getInicio().toString()
                << ", Fin: " << getFin().toString()
                << ", Color: " << getColor().toString();
            return oss.str();
        }
        
        ~Circle() = default;

};
class Rectangle : virtual public Shape {
    public:
        Rectangle(Point inicio, Point fin, Color color) : Shape(inicio, fin, color){};
        
        std::string toString() {
            std::ostringstream oss;
            oss << "Circle: " << "Inicio: " << getInicio().toString()
                << ", Fin: " << getFin().toString()
                << ", Color: " << getColor().toString();
            return oss.str();
        }
        
        ~Rectangle() = default;
};
class Toolbar {};
class Canvas {};
class Command {
    public:
        void add(Shape shape){
            std::cout << "Shape added." << std::endl;
        }
        void remove(int id){
            std::cout << "ID removed." << std::endl;
        }
        void move(int id, Point point){
            std::cout << "Object with id " << std::to_string(id) << "moved to pint " << std::to_string(point.getX()) << std::endl;
        }
};

int main (){
    Circle circle(Point(0, 0), Point(100, 100), Color(0, 0, 0, 0, 0));  
    std::cout << circle.toString() << std::endl;
    return 0;
}