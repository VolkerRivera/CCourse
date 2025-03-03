#include "app.h"
#include <iostream>

App::App(Toolbar &toolbar, Canvas &canvas)
    : toolbar(toolbar), canvas(canvas)
{
}

void App::run()
{
    int opcion;
    int id = 0;
    std::string cmd;

    do
    {
        showMenu();
        std::cin >> opcion;
        int id_rmv;

        switch (opcion)
        {
        case 1:
        {
            std::cout << "Creando un shape..." << std::endl;
            // Se crea el shape mediante la interfaz.
            std::unique_ptr<Shape> newShape = shapeInterface(toolbar, id);
            CommandCreate create(canvas, std::move(newShape));
            create.run();
            id++;
            break;
        }
        case 2:
        {
            do
            {
                clear();
                std::cout << "Listando todos los shapes...\n" << std::endl;
                CommandList list(canvas);
                list.run();
                std::cout << "\nVolver al menu principal? (y/otra tecla): ";
                std::cin >> cmd;
            } while(cmd != "y");
            break;
        }
        case 3:
        {
            std::cout << "Introduzca el ID del shape que desea eliminar: " << std::endl;
            std::cin >> id_rmv;
            CommandRemove remove(canvas, id_rmv);
            remove.run();
            break;
        }
        case 4:
        {
            int id_mv;
            std::cout << "Introduzca el ID del shape que desea mover: " << std::endl;
            std::cin >> id_mv;
            CommandMove move(canvas, id_mv);
            move.run();
            break;
        }
        case 5:
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 5);
}
