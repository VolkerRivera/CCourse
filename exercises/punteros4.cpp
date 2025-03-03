#include <iostream>
#include <memory>  // Para std::unique_ptr
 
class MiClase {
public:
    int valor;
 
    // Constructor normal
    MiClase(int v) : valor(v) {
        std::cout << "Constructor normal\n";
    }
 
    // Constructor de copia (eliminado porque unique_ptr no permite copia)
    MiClase(const MiClase&) = delete;
 
    // Constructor de movimiento
    MiClase(MiClase&& otra) noexcept : valor(otra.valor) {
        std::cout << "Constructor de movimiento\n";
        otra.valor = 0;  // Indicar que el objeto fue movido
    }
 
    // Destructor
    ~MiClase() {
        std::cout << "Destructor\n";
    }
};
 
// Función que recibe un unique_ptr por valor (mueve la propiedad del puntero)
void funcionConUniquePtr(std::unique_ptr<MiClase> obj) {
    std::cout << "Dentro de funcionConUniquePtr, valor: " << obj->valor << "\n";
}
 
void funcionConReferencia(const std::unique_ptr<MiClase>& obj) {
    if (obj) { // Comprobamos si obj no es nullptr
        std::cout << "Dentro de funcionConReferencia, valor: " << obj->valor << "\n";
    } else {
        std::cout << "Dentro de funcionConReferencia, pero obj es nullptr\n";
    }
}
 
 
int main() {
    // Crear un objeto en un unique_ptr
    std::unique_ptr<MiClase> obj1 = std::make_unique<MiClase>(10);
 
    std::cout << "\nPasando a funcionConUniquePtr (se mueve)...\n";
    funcionConUniquePtr(std::move(obj1)); // Activa el constructor de movimiento      
 
    std::cout << "\nPasando a funcionConReferencia...\n";
    funcionConReferencia(obj1); // No activa constructores
 
    std::cout << "\nFin del main\n";
    return 0;
}