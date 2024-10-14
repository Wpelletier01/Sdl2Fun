#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "core/texture.h"
#include "declaration.h"
#include <map>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;


class AssetManager {

    public:

        int init(SDL_Renderer* renderer);


    private:

        std::map<std::string,Texture> textures; 


};