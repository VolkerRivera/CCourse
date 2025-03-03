/*
Crear una clase repository:
que herede el metodo add de una clase add
que herde el metodo update de una clase update
que herde el metodo remove de una clase remove
que herde el metodo get de una clase get
 
Tanto update como remove heredan el metodo get de 
la clase get
 
Update* update = new Repository()
 
update.get()
update.update() 
*/

#include <iostream>

class Add {
    public:
    virtual void add() const = 0;
    virtual ~ Add(){};
};

class Get {
    public:
    Get(){
        std::cout << "Get creado" << std::endl;
    }
    virtual void get() const = 0;
    virtual ~ Get(){};
};

class Update : virtual public Get {
    public:
    virtual void update() const = 0;
    virtual ~ Update(){};
};

class Remove : virtual public Get {
    public:
    virtual void remove() const = 0;
    virtual ~ Remove(){};
};

class Repository : public Add, public Update, public Remove {
    public:
    void add() const override {
        std::cout << "Repository Class: Add method implemented." << std::endl;
    }
    void update() const override {
        std::cout << "Repository Class: Update method implemented." << std::endl;
    }
    void remove() const override {
        std::cout << "Repository Class: Remove method implemented." << std::endl;
    }
    void get() const override {
        std::cout << "Repository Class: Get method implemented." << std::endl;
    }
    virtual ~ Repository(){};
};

int main(){

    Update* update = new Repository();
 
    update->get();
    update->update();

    delete update;

    const Update &update_b = Repository();
    update_b.get();
    update_b.update();

    return 0;
}