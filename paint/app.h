#ifndef APP_H
#define APP_H

#include <string>
#include "toolbar.h"
#include "canvas.h"
#include "util.h"
#include "commands.h"
#include "GestorFichero.h"

class App
{
private:
    Toolbar &toolbar;
    Canvas &canvas;
public:
    App(Toolbar &toolbar, Canvas &canvas);
    void run();
};

#endif // APP_H
