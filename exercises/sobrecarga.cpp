#include <iostream>

class MiEntero{
    private:
        int entero;
    public:
        MiEntero(int entero) { this->entero = entero; }
        int getEntero() { return entero; }
        friend MiEntero& operator+(const MiEntero& e1, const MiEntero& e2);
        MiEntero& operator-(const MiEntero& e2) {
            return MiEntero(this->entero - e2.entero);
        }
    };
MiEntero& operator+(const MiEntero& e1, const MiEntero& e2) {
    return MiEntero(e1.entero + e2.entero);
}
int main() {
    MiEntero e1(8);
    MiEntero e2(3);
    MiEntero e3 = e1 + e2;
    MiEntero e4 = e1 - e2;
    std::cout << e3.getEntero() << " " << e4.getEntero() << std::endl;
}