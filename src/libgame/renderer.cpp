#include "renderer.h"



int Renderer::init(SDL_Window* win, entt::registry* registry) 
{

    this->mrenderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    if (this->mrenderer == NULL) {
        printf("Couldn't create renderer. Error: %s\n",SDL_GetError());
        return 1;
    } 
        
    SDL_SetRenderDrawColor(this->mrenderer,255,255,255,255);
    
    this->textures = AssetManager::loadTextures(this->mrenderer);
    this->mregistry = registry;

    return 0;
}

Renderer::~Renderer()
{
    for (const auto& entry : this->textures ){
        SDL_DestroyTexture(entry.second);
    }

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

void Renderer::renderAll()
{
    auto view = this->mregistry->view<Drawable>();

    for (auto entity : view) {
        const auto& drawable = view.get<Drawable>(entity);

        SDL_RenderCopy(
            this->mrenderer,
            this->textures[drawable.textureId],
            &drawable.src,
            &drawable.dst
        );

    }

}
