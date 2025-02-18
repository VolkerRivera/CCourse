#include <iostream>
#include <string>
#include <vector>

int main(){
    int number1;
    std::vector<int> numbers;

    do{
        std::cout << "Introduzca un 0: ";
        std::cin >> number1;
        if(number1 == 0)
            break;
        numbers.push_back(number1);

    }while(number1 != 0);

    std::cout << "Los elementos del vector son: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}