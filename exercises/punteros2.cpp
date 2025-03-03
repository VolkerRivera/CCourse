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
    }
 
    // Destructor
    ~MiClase() {
        std::cout << "Destructor\n";
    }
};
 
 
void funcionPorValor(MiClase obj) {
    std::cout << "Dentro de funcionPorValor " << obj.valor  << std::endl;
}
 
void funcionPorReferencia(const MiClase& obj) {
    std::cout << "Dentro de funcionPorReferencia " << obj.valor << std::endl;
}
 
int main() {
    std::cout << "Creando objeto...\n";
    MiClase obj1(10);
 
    std::cout << "\nPasando a funcionPorValor...\n";
    funcionPorValor(obj1);
 
    std::cout << "\nForzando constructor de movimiento...\n";
    funcionPorValor(std::move(obj1));
   
 
    std::cout << "\nPasando a funcionPorReferencia...\n";
    funcionPorReferencia(obj1);
 
    std::cout << "\nFin del main\n";
    return 0;
}