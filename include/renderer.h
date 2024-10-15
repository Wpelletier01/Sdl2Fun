#pragma once

#include "drawable.h"
#include "asset_manager.h"

class Renderer {

    public:
        int init(SDL_Window* win);

        ~Renderer();

        void clear();
        void present();
        void render(Drawable* drawable, AssetManager* asset_manager);

        SDL_Renderer* getSdlRenderer();

    private:

        SDL_Renderer* mrenderer;

};