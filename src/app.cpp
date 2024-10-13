#include "app.h"



int App::init(int width, int height, const char* title) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't init sdl");
        return 1;                
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
        return 1;
    }

    this->surface = SDL_GetWindowSurface(this->window);

    if (this->surface == NULL ) {
        printf("Couldn't retreive surface from window. Error: %s",SDL_GetError());
        return 1;
    }

    this->renderer = SDL_CreateRenderer(this->window, "main");

    if (this->renderer == NULL) {
        printf("Couldn't create main renderer. Error: %s",SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(this->renderer,255,255,255,255)

    if (this->assetManager->init() > 0) {
        printf("Asset loader failed");
        return 1;
    }


    return 0;
}

void App::close() {

    SDL_FreeSurface( this->surface);
    this->surface = NULL;
    SDL_DestroyWindow( this->window );
    this->window = NULL;
    SDL_Quit();

    printf("You close the app\n");
}



void App::run() {
    
    SDL_Event event;
    this->running = true;

    while (this->running) {
        
        SDL_RenderClear(renderer)

        while( SDL_PollEvent( &event ) ) { 

            switch (event.type) {

                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    this->handleInput(event.key);
                    break; 
                case SDL_QUIT:
                    this->running = false;
                    break;
                default:
                    break;
            }

        } 
    }

    this->close();
}

void App::handleInput(SDL_KeyboardEvent key_event) {

    if (key_event.type == SDL_KEYDOWN) {

        switch( key_event.keysym.sym) {

            case SDLK_ESCAPE:
                this->running = false;
                break;
            default:
                break;

        }
    }


}