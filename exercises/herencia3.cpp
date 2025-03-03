/* Crear una clase que no se pueda instanciar y que sus derivadas se puedan instanciar
Esta clase debe de tener un atributo id de solo lectura */

#include <iostream>
#include <string>

class A {
    protected:
        int id;

    public:
        A(int id) : id(id){
            std::cout << "Instancia de A creada." << std::endl;
        }
        virtual int getId() const = 0;
        virtual ~ A() = default;
};

class B : virtual public A {
    public:
        B(int id) : A(id){
            std::cout << "Instancia de B creada." << std::endl;
        }
        int getId() const override{
            return id;
        }
        ~ B() = default;
};

int main(){
    //A* a = new A(2);
    B* b = new B(1);
    std::cout << "Id de la instancia creada: " << std::to_string(b->getId()) << std::endl;

    return 0;
}

/* Se puede implementar de la forma que está activa ya que por definición la abstracta no deja ser implementada, pero se tiene que repetir la definición de getId las veces necesarias en las herederas.
Por lo que la forma de implementarlo sin repetir las deifiniciones de getId en las hijas sería con:

class A{
   private:
	int id;
   public:
	A()=deleted
        int getId() const {return id;}
   protected:
	A(int id):id(id){}
};
 
class B:public A{  
 
    B(int id):A(id){}
}
    
*/