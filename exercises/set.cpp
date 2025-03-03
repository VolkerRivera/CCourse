#include <iostream>
#include <set>

class A {
    private:
        int id;

    public:
        A(int id) : id(id){}
        int getId(){
            return id;
        }
        // Sobrecarga del operador <
    bool operator <(const A& other) const {
        return id < other.id; // Compara por id
    }
        ~ A() = default;
};

int main(){

    std::set<A> mySet;
    mySet.insert(A(1));
    mySet.insert(A(1));
    mySet.insert(A(1));
    mySet.insert(A(2));

    for (auto a : mySet) {
        std::cout << "Nombre: " << a.getId() << std::endl;
    }
    return 0;
}