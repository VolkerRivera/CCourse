#include <iostream>
#include <string>

bool esPrimo(int number){
    if(number <= 1) return false;
    for(int i=2; i*i<number; i++){
        if(number%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int number;
    std::string text_input;

    std::cout << "Introduzca un entero: ";
    std::cin >> number;

    if(esPrimo(number)){
        std::cout << number << " es primo. " << std::endl;
    }else{
        std::cout << number << " no es primo. " << std::endl;
    }

}