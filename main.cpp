#include <iostream>

#include "app.h"

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;



// TODO: universalize log error message



int main() {

    App app;

    if (app.init(WIN_WIDTH,WIN_HEIGHT,"SDL_FUN") < 0) {
        printf("App initialisation failed");
        return 1;
    }

    app.run();

    return 0;
}