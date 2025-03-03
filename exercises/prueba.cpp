#include <iostream>

class A {
    public:
        void saluda() { std::cout << "Hola A" << std::endl; }
        A() { std::cout << "Creado A" << std::endl; }
};

class B: virtual public A {
};

class C: virtual public A{
};

class D : public B, public C {};

int main() {
    D* d = new D();
    d->saluda();

    return 0;
}