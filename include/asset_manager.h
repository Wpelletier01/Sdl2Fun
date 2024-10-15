#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "declaration.h"
#include <string>
#include <map>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;


class AssetManager {

    public:

        int init(SDL_Renderer* renderer);

        SDL_Texture* getTexture(std::string name) const;

    private:
        SDL_Texture* load_texture(fs::path fpath, SDL_Renderer* renderer);
        std::map<std::string,SDL_Texture*> textures; 


};