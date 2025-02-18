#include <iostream>
#include <string>

int main(){
    int number1;
    int number2;

    std::cout << "Introduzca el primer entero: ";
    std::cin >> number1;

    std::cout << "Introduzca el segundo entero: ";
    std::cin >> number2;

    while(number1 != number2){
        if(number1 < number2){
            std::cout << number1 << " es menor que " << number2 << ". Vuelva a insertar un entero: " << std::endl;
        std::cin >> number2;
        }
        if(number1 > number2){
            std::cout << number1 << " es mayor que " << number2 << ". Vuelva a insertar un entero: " << std::endl;
        std::cin >> number2;
        }
        
    }

    std::cout << number1 << " es igual a " << number1 << std::endl;

}