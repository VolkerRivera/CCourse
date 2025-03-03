#include <iostream>
#include <memory>
 
template <typename T, typename... Args>
std::unique_ptr<T> createInstance(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...); // sirve para crear punteros inteligentes que después no haga falta destruirlos
}
 
class MiClase {
public:
    MiClase(int a, double b, std::string c) {
        std::cout << "MiClase creada con valores: " << a << ", " << b << ", " << c << std::endl;
    }
    ~MiClase(){
        std::cout << "Destructor" << std::endl;
    }
};
 
int main() {
    auto instancia = createInstance<MiClase>(42, 3.14, "Hola Mundo"); // createInstance devuelve un unique_ptr
    MiClase* cl = instancia.get();    
    if(cl){ // aqui se comprueba que el pntero no es null ptr
        std::cout << "MiClase creada" << std::endl;
    }
    std::cout << "before return0" << std::endl;
    return 0;
    // cuando se cierra el programa se destruye el puntero
}