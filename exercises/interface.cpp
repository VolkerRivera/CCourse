 /* En el mundo de las aves existen pinguinos y aguilas los pinguinos pesan 5 kg
y las aguilas pesan 10 kg y vuelan a 100 km/h */

#include <iostream>

class Ave {
    protected:
        int peso;
        std::string nombre;
    public:
        Ave(int peso, std::string nombre) : peso(peso), nombre(nombre){};
        virtual int getPeso() = 0;
        virtual void showAllData() = 0;
};

class Pinguino : public Ave{
    private:
        int velocidadNado;
    public:
        Pinguino(int peso, std::string nombre, int velocidadNado): Ave(peso, nombre), velocidadNado(velocidadNado){}
        int getVelocidadNado(){return velocidadNado;}
        int getPeso() override { // Implementación del método virtual puro
            return peso; // Acceder al peso desde la clase base
        }
        void showAllData() override { // Implementación del método virtual puro
            std::string data = "Nombre: " + nombre + ", peso: " + std::to_string(peso) + " kg, velocidad de nado: " + std::to_string(velocidadNado) + " km/h";
            std::cout << data << std::endl;
        }
    };

class Aguila : public Ave{
    private:
        int velocidadVuelo;
    public:
        Aguila(int peso, std::string nombre, int velocidadVuelo) : Ave(peso, nombre), velocidadVuelo(velocidadVuelo){}
        int getVelocidadVuelo(){return velocidadVuelo;}
        int getPeso() override { // Implementación del método virtual puro
            return peso; // Acceder al peso desde la clase base
        }
        void showAllData() override { // Implementación del método virtual puro
            std::string data = "Nombre: " + nombre + ", peso: " + std::to_string(peso) + " kg, velocidad de nado: " + std::to_string(velocidadVuelo) + " km/h";
            std::cout << data << std::endl;
        }
};

int main(){
    Pinguino* pinguino = new Pinguino(5, "pingu", 20);
    pinguino->showAllData();
    delete pinguino;

    Aguila* aguila = new Aguila(10, "aguila", 100);
    aguila->showAllData();
    delete aguila;
    
    return 0;
}