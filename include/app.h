#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

#pragma once

class App {

    public:

        int init(int width, int height, const char* title);
        void run();

    private:
        SDL_Window *window = NULL;
        SDL_Surface *surface = NULL;


};