#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

#include "asset_manager.h"
#include "renderer.h"
#include "player.h"

class App {

    public:

        int init(int width, int height, const char* title);

        
        void run();
        void close();

        AssetManager *assetManager = new AssetManager();
    
    private:
        void handleInput(SDL_KeyboardEvent key_event);
        
        SDL_Window *window = NULL;
        Renderer renderer;        
        
        bool running = false;
        // entities
        Player* player;

};