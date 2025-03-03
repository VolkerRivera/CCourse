#include <iostream>
 
class MiClase {
public:
    int valor;
 
    // Constructor normal
    MiClase(int v) : valor(v) {
        std::cout << "Constructor normal\n";
    }
 
    // Constructor de copia
    MiClase(const MiClase& otra) : valor(otra.valor) {
        std::cout << "Constructor de copia\n";
    }
 
    // Constructor de movimiento
    MiClase(MiClase&& otra) noexcept : valor(otra.valor) {
        std::cout << "Constructor de movimiento\n";
        otra.valor = 0; // Indicar que el objeto fue movido
    }
 
    // Destructor
    ~MiClase() {
        std::cout << "Destructor\n";
    }
};
 
// Función que recibe un puntero a MiClase
void funcionConPuntero(MiClase* obj) {
    std::cout << "Dentro de funcionConPuntero, valor: " << obj->valor << "\n";
}
 
int main() {
    std::cout << "Creando objeto...\n";
    MiClase* obj1 = new MiClase(10);
 
    std::cout << "\nPasando a funcionConPuntero...\n";
    funcionConPuntero(obj1); // No activa copia ni movimiento
 
    std::cout << "\nLiberando memoria...\n";
    delete obj1; // Llamará al destructor
 
    std::cout << "\nFin del main\n";
    return 0;
}