/* A partir de la clase MiClase, agreagar a un vector 4 instancias de la misma con los valores 1, 2, 3 y 4.
Escribir un algoritmo para filtrar los pares y agregarlos a un nuevo vector. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class MiClase{
    public:
        int valor;
        MiClase(int v) : valor(v){}
};

int main(){
    std::vector<MiClase> myVector = {MiClase(1), MiClase(2), MiClase(3), MiClase(4)};
    std::vector<MiClase> outVector;

    std::copy_if(myVector.begin(), myVector.end(), std::back_inserter(outVector), [](MiClase a){return a.valor%2 == 0;});
    for (MiClase x: outVector) {
        std::cout << ' ' << std::to_string(x.valor) << std::endl;
    }
    return 0;
}