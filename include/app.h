#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

#include "asset_manager.h"

class App {

    public:

        int init(int width, int height, const char* title);
        void run();
        void close();
    private:

        void handleInput(SDL_KeyboardEvent key_event);
        
        SDL_Window *window = NULL;
        SDL_Surface *surface = NULL;
        bool running = false;
        AssetManager *assetManager = new AssetManager();

};