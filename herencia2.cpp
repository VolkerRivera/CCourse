/* Definir una clase de la cual no se pueda heredar */
#include <iostream>

class A final {
    public:
        A() {
            std::cout << "Instancia de A creada." << std::endl;
        }
};

class B : virtual public A{

};

int main(){
    return 0;
}

