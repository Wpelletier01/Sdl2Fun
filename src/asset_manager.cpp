#include "asset_manager.h"


int AssetManager::init(SDL_Renderer* renderer) {

    // Load texture 

    fs::path p;

    for (const auto &entry : fs::directory_iterator(ASSET_IMG_DIR)) {

        p = entry.path();

        Texture tex(p,renderer);

        this->textures.insert({(std::string)p.filename(),tex});

        SDL_Log("load texture: '%s'",entry.path().c_str());
    }



    //    


    return 0;
}

