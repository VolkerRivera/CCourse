#include <iostream>
#include <memory>

class A{
    private:
        int a;
    public:
        A(int a) = delete; // copia
        A(const A& other) : a(other.a){ // movimiento

        } 
        A(A&& other) : a(a){ // referencia

        }
        ~A() = default;
};

void fn(std::unique_ptr<A>& a){
    std::cout << "fn executed." << std::endl;
}

int main(){

    //A a(1);
    //A* b = new A(1);
    std::unique_ptr<A> c = std::make_unique<A>(10);
    fn(c);


    return 0;
}