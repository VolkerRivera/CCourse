#include "GestorFichero.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream> // Opcional si se requiere imprimir información en la consola

GestorFichero::GestorFichero(const std::string& nombreFichero)
    : nombreFichero(nombreFichero) {}

GestorFichero::~GestorFichero() {
    // No es necesario liberar recursos de forma explícita en este caso.
}

void GestorFichero::escribir(const std::string& texto, bool append) {
    try {
        // Configuración del modo de apertura.
        std::ios_base::openmode modo = std::ios::out;
        if (append) {
            modo |= std::ios::app;
        }

        std::ofstream archivo(nombreFichero, modo);
        if (!archivo) {
            throw std::runtime_error("Error al abrir el fichero para escribir: " + nombreFichero);
        }

        archivo << texto;

        if (!archivo.good()) {
            throw std::runtime_error("Error al escribir en el fichero: " + nombreFichero);
        }

        archivo.close();
    }
    catch (const std::exception& e) {
        // Se re-lanza la excepción para que el usuario de la clase pueda gestionarla.
        throw std::runtime_error(std::string("GestorFichero::escribir - ") + e.what());
    }
}

std::string GestorFichero::leer() {
    try {
        std::ifstream archivo(nombreFichero);
        if (!archivo) {
            throw std::runtime_error("Error al abrir el fichero para leer: " + nombreFichero);
        }

        std::stringstream buffer;
        buffer << archivo.rdbuf();

        if (archivo.fail() && !archivo.eof()) {
            throw std::runtime_error("Error al leer el fichero: " + nombreFichero);
        }

        archivo.close();
        return buffer.str();
    }
    catch (const std::exception& e) {
        throw std::runtime_error(std::string("GestorFichero::leer - ") + e.what());
    }
}
