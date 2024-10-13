#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

#pragma once

class App {

    public:

        int init(int width, int height, const char* title);
        void run();

    private:

        void handle_input(SDL_KeyboardEvent key_event);

        SDL_Window *window = NULL;
        SDL_Surface *surface = NULL;
        bool running = false;


};