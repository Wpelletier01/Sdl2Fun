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
        static std::map<std::string,SDL_Texture*> loadTextures(SDL_Renderer* renderer);
        static SDL_Texture* loadSingleTexture(fs::path file, SDL_Renderer* renderer);
};