#pragma once


#include <SDL2/SDL.h>
#include <SDL_image.h>



class Texture {

    public:

        Texture(const char* fpath, SDL_Renderer* renderer);
        ~Texture();

        SDL_Texture* mtexture = NULL;

};