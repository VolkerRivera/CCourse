#include <iostream>
#include <string>

int main(){
    int number;
    std::string text_input;

    std::cout << "Introduzca un entero: ";
    std::cin >> number;

    if(number%2 == 0){
        std::cout << number << " es divisible entre 2. " << std::endl;
    }else{
        std::cout << number << " no es divisible entre 2. " << std::endl;
    }

    


}