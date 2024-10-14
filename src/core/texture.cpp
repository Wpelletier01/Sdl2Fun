#include "core/texture.h"



Texture::Texture(const char* fpath, SDL_Renderer* renderer) 
{
    SDL_Surface* surfaceLoad = NULL;
    
    surfaceLoad = IMG_Load(fpath);

    if (surfaceLoad == NULL) {
        SDL_LogError(1,"Couldn't load texture '%s'. %s",fpath,SDL_GetError());
    } else {

        this->mtexture = SDL_CreateTextureFromSurface(renderer,surfaceLoad);

        if (this->mtexture == NULL) {
            SDL_LogError(1,"Couldn't create texture '%s'. %s",fpath,SDL_GetError());
        }
    }


}


Texture::~Texture() 
{
    SDL_DestroyTexture(this->mtexture);
    printf("texture destroy");
}