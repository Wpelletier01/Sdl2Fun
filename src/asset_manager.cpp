#include "asset_manager.h"


int AssetManager::init(SDL_Renderer* renderer) 
{

    // Load texture 

    fs::path p;
    std::string fname;

    for (const auto &entry : fs::directory_iterator(ASSET_IMG_DIR)) {

        p = entry.path();
        fname = p.stem();

        SDL_Texture* texture = this->load_texture(p,renderer);

        this->textures.insert({fname,texture});

        SDL_Log("load texture: '%s'",fname.c_str());
    }


    return 0;
}



SDL_Texture* AssetManager::getTexture(std::string name) const
{
    auto search = this->textures.find(name); 
    if (search != this->textures.end()) {
        return search->second;
    } 

    SDL_LogWarn(1, "No texture with the name '%s' exist", name.c_str());
    
    return nullptr;
}

SDL_Texture* AssetManager::load_texture(fs::path fpath, SDL_Renderer* renderer)
{

    SDL_Surface* surfaceLoad = NULL;
    SDL_Texture* texture;
    surfaceLoad = IMG_Load(fpath.c_str());

    if (surfaceLoad == NULL) {
        SDL_LogError(1,"Couldn't load texture '%s'. %s",fpath.c_str(),SDL_GetError());
        return nullptr;
    } 

    texture = SDL_CreateTextureFromSurface(renderer,surfaceLoad);

    if (texture == NULL) {
        SDL_LogError(1,"Couldn't create texture '%s'. %s",fpath.c_str(),SDL_GetError());
        return nullptr;
    }
    
    return texture;

}