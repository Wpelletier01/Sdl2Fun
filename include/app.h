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

        // will have is own class
        SDL_Renderer *renderer = NULL;         
        AssetManager *assetManager = new AssetManager();
    
    private:
        void handleInput(SDL_KeyboardEvent key_event);
        
        SDL_Window *window = NULL;
        bool running = false;

};