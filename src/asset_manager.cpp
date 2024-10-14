#include "asset_manager.h"


int AssetManager::init(SDL_Renderer* renderer) 
{

    // Load texture 

    fs::path p;
    std::string fname;

    for (const auto &entry : fs::directory_iterator(ASSET_IMG_DIR)) {

        p = entry.path();
        fname = p.stem();

        Texture tex(p,renderer);

        this->textures.insert({fname,tex});

        SDL_Log("load texture: '%s'",fname.c_str());
    }


    return 0;
}



SDL_Texture* AssetManager::getTexture(std::string name)
{
    auto search = this->textures.find(name); 
    if (search != this->textures.end()) {
        return search->second.mtexture;
    } 

    SDL_LogWarn(1, "No texture with the name '%s' exist", name.c_str());
    
    return NULL;

}

