#include "toolbar.h"
#include "canvas.h"
#include "app.h"
#include "shape.h"
#include <memory>

int main()
{
    Toolbar toolbar;
    // Registrar las funciones fábrica para Circle y Rectangle.
    toolbar.registerShape(ShapeType::CIRCLE, Circle::create);
    toolbar.registerShape(ShapeType::RECTANGLE, Rectangle::create);
    
    Canvas canvas;
    App app(toolbar, canvas);
    app.run();
    
    return 0;
}
