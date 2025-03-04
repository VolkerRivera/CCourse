#ifndef GESTORFICHERO_H
#define GESTORFICHERO_H

#include <string>

class GestorFichero {
public:
    // Constructor que recibe el nombre del fichero.
    GestorFichero(const std::string& nombreFichero);

    // Destructor (por defecto).
    ~GestorFichero();

    // Método para escribir en el fichero.
    // Si append es true, se añade el texto al final; en caso contrario, se sobrescribe.
    // Lanza una excepción en caso de error.
    void escribir(const std::string& texto, bool append = false);

    // Método que lee el contenido completo del fichero y lo devuelve en un string.
    // Lanza una excepción en caso de error.
    std::string leer();

private:
    std::string nombreFichero;
};

#endif // GESTORFICHERO_H
