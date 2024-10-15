#include "renderer.h"



int Renderer::init(SDL_Window* win) 
{

    this->mrenderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    if (this->mrenderer == NULL) {
        printf("Couldn't create renderer. Error: %s\n",SDL_GetError());
        return 1;
    } 
        
    SDL_SetRenderDrawColor(this->mrenderer,255,255,255,255);
    
    return 0;
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(this->mrenderer);
}

void Renderer::clear()
{
    SDL_RenderClear(this->mrenderer);
}

void Renderer::present()
{
    SDL_RenderPresent(this->mrenderer);
}

void Renderer::render(Drawable* drawable, AssetManager* asset_manager)
{ 
    int r = SDL_RenderCopy(
        this->mrenderer,
        asset_manager->getTexture(drawable->getTexture()),
        drawable->getSource(),
        drawable->getDestination()
    );


}

SDL_Renderer* Renderer::getSdlRenderer() 
{
    return this->mrenderer;
}