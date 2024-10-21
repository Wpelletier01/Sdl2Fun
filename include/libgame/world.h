#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "nlohmann/json.hpp"
#include "asset_manager.h"


class World
{

    public:
        World(std::string tilemap, SDL_Renderer* renderer);

        int getWidth();
        int getHeight();
        std::vector<SDL_Texture*>& getTiles();
        std::vector<int>& getMap();

    private:
        
        int wSize, hSize, tileSize;
        std::vector<SDL_Texture*> tiles;
        std::vector<int> tileMap;



};