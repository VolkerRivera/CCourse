#include <iostream>
#include <exception>
#include <string>
 
class MiExcepcion : public std::exception
{
private:
    std::string mensaje;
 
public:
   
    MiExcepcion(const std::string& msg) : mensaje(msg) {} 
    const char* what() const noexcept override // noexcept significa que ese metodo no lanza excepciones
    {
        return mensaje.c_str();
    }
};
 
int main()
{
    try
    {        
        throw MiExcepcion("Se ha producido un error grave");
    }
    catch (const MiExcepcion& e)
    {
        std::cerr << "Capturada MiExcepcion: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Capturada std::exception: " << e.what() << std::endl;
    }
 
    return 0;
}
 
 