#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <SDL2/SDL.h>
#include "nlohmann/json.hpp"
#include "asset_manager.h"

namespace fs = std::filesystem;

class World
{

    public:
        World(std::string worldDir, SDL_Renderer* renderer);

        int getWidth();
        int getHeight();
        std::vector<SDL_Texture*>& getTiles();
        std::vector<int>& getMap();

    private:
        
        int wSize, hSize, tileSize;
        std::vector<SDL_Texture*> tiles;
        std::vector<int> tileMap;



};