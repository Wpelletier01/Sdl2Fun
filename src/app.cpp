#include "app.h"



int App::init(int width, int height, const char* title) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't init sdl");
        return -1;                
    }

    this->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
            

    if (this->window == NULL) {
        printf("Couldn't create a window. Error: %s",SDL_GetError());
        return -1;
    }

    this->surface = SDL_GetWindowSurface(this->window);

    if (this->surface == NULL ) {
        printf("Couldn't retreive surface from window. Error: %s",SDL_GetError());
        return -1;
    }


    return 0;
}



void App::run() {

    SDL_FillRect(this->surface,NULL,SDL_MapRGB(this->surface->format,255,255,255));
    SDL_UpdateWindowSurface(this->window);

    SDL_Event event;
    bool is_running = true;

    while (is_running) {
    
        while( SDL_PollEvent( &event ) ) { 
            if( event.type == SDL_QUIT ) is_running = false; 
        } 
    }

}