#include "commands.h"

// CommandCreate
CommandCreate::CommandCreate(Canvas &canvas, std::unique_ptr<Shape> shape)
    : receiver(canvas), shape(std::move(shape))
{
}

void CommandCreate::run()
{
    receiver.add(std::move(shape));
}

// CommandList
CommandList::CommandList(Canvas &canvas)
    : receiver(canvas)
{
}

void CommandList::run()
{
    receiver.list();
}

// CommandRemove
CommandRemove::CommandRemove(Canvas &canvas, int id)
    : receiver(canvas), id(id)
{
}

void CommandRemove::run()
{
    receiver.remove(id);
}

// CommandMove
CommandMove::CommandMove(Canvas &canvas, int id)
    : receiver(canvas), id(id)
{
}

void CommandMove::run()
{
    Point new_start;
    std::cout << "Introduzca el nuevo punto de inicio:" << std::endl;
    std::cin >> new_start;
    std::cout << "Nuevo inicio: " << new_start.toString() << std::endl;

    Point new_end;
    std::cout << "Introduzca el nuevo punto final:" << std::endl;
    std::cin >> new_end;
    std::cout << "Nuevo final: " << new_end.toString() << std::endl;

    receiver.move(id, new_start, new_end);
}

// CommandExport
CommandExport::CommandExport(Canvas &canvas)
    : receiver(canvas)
{
}

void CommandExport::run()
{
    receiver.export_to_file();
}