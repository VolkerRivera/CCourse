#include <iostream>
#include <vector>
#include <functional>

/* TEMPLATES DE OPERACIONES */
template <typename T>
T suma (T a, T b){
    return a + b;
}

template <typename T>
T resta (T a, T b){
    return a - b;
}

template <typename T>
T mult (T a, T b){
    return a * b;
}

template <typename T>
T div (T a, T b){
    if(b != 0){
        return a/b;
    }else{
        return 0;
    }
}

/* Definimos un alias para el tipo de función con template, para no tener que usar tantas T */
template <typename T>
using Operation = std::function<T(T, T)>; // <Output(Input1, Input2)>



int main(){

    return 0;
}

/* #include <iostream>
#include <vector>
#include <functional>
 
// Funciones de operaciones básicas con template
template <typename T>
T add(T a, T b) { return a + b; }
 
template <typename T>
T subtract(T a, T b) { return a - b; }
 
template <typename T>
T multiply(T a, T b) { return a * b; }
 
template <typename T>
T divide(T a, T b) { return b != 0 ? a / b : 0; }
 
// Definimos un alias para el tipo de función con template
template <typename T>
using Operation = std::function<T(T, T)>;
 
// Función que devuelve un vector con punteros a las operaciones
template <typename T>
std::vector<Operation<T>> operations() {
    return {add<T>, subtract<T>, multiply<T>, divide<T>};
}
 
int main() {    
 
    std::cout << "enteros" << std::endl;
    for(auto operation:operations<int>()){
        std::cout << operation(2,2) << std::endl;
    }
 
    std::cout << "dobles" << std::endl;
    for(auto operation:operations<double>()){
        std::cout << operation(2.5,2.1) << std::endl;
    }
 
    return 0;
}*/