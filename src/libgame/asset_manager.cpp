#include "asset_manager.h"

std::map<std::string,SDL_Texture*> AssetManager::loadTextures(SDL_Renderer* renderer)
{

    std::map<std::string,SDL_Texture*> textures;
    fs::path p;
    std::string fname;
    SDL_Surface* surfaceLoad;
    SDL_Texture* texture;

    for (const auto &entry : fs::directory_iterator(ASSET_IMG_DIR)) {

        p = entry.path();
        fname = p.stem();

        surfaceLoad = IMG_Load(p.c_str());

        if (surfaceLoad == NULL) {
            SDL_LogError(1,"Couldn't load texture '%s'. %s",p.c_str(),SDL_GetError());
            return textures;
        } 

        texture = SDL_CreateTextureFromSurface(renderer,surfaceLoad);

        if (texture == NULL) {
            SDL_LogError(1,"Couldn't create texture '%s'. %s",p.c_str(),SDL_GetError());
            return textures;
        }

        textures.insert({fname,texture});

        SDL_Log("load texture: '%s'",fname.c_str());
    }

    return textures;
}

SDL_Texture* AssetManager::loadSingleTexture(fs::path file, SDL_Renderer* renderer)
{

    SDL_Surface* surfaceLoad = NULL;
    SDL_Texture* texture = NULL;

    surfaceLoad = IMG_Load(file.c_str());

    if (surfaceLoad == NULL) {
        SDL_LogError(0,"Couldn't load texture '%s'. %s",file.c_str(),SDL_GetError());
        
        return texture;
    } 

    texture = SDL_CreateTextureFromSurface(renderer,surfaceLoad);

    if (texture == NULL) {
        SDL_LogError(0,"Couldn't create texture '%s'. %s",file.c_str(),SDL_GetError());
        return nullptr;
    }

    SDL_Log("load texture: '%s'",file.c_str());
    return texture;
    
}