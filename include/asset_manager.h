#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class AssetManager {

    public:
        int init(SDL_Renderer* renderer);

    private:
        SDL_Texture* loadTexture(const char* img, SDL_Renderer* renderer);

        SDL_Texture* playerSprite = NULL;
};