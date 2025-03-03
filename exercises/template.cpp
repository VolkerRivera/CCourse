#include <iostream>
#include <cstring>

template <typename T1, typename T2> // es el compilador el que detecta el tipo de variable que entra
T1 max(T1 a, T2 b) {
	if (strcmp(typeid(a).name(), typeid(b).name()) == 0) { return (a>b) ? a : b;}
	else {
		return a; }
}
int main(){
	int a = 3; int b = 5;
	float fa = 1.2; float fb = 1.9;
	std::cout << max(a, b) << std::endl;
	std::cout << max(fa, b) << std::endl;
    std::cout << max<int>(fa, fb) << std::endl; // se fuerza que aunque el input sea float, la salida sea int
    return 0;
}