#include "world.h"

World::World(std::string tilemap, SDL_Renderer* renderer)
{
    this->tiles.push_back(NULL);

    std::ifstream input(tilemap);

    if (!input.is_open()) {
        SDL_LogError(0, "couldn't open tilemap '%s'",tilemap.c_str());
    }

    nlohmann::json data;

    try {
        input >> data;
    } catch (const nlohmann::json::parse_error& e) {
        SDL_LogError(0,"Couldn't parse json: %s", e.what());
        return;
    }

    this->wSize = data["width"];
    this->hSize = data["height"];
    this->tileSize = data["tilewidth"];


    auto tilesets = data["tilesets"];

    if (!tilesets.is_array()) {
        SDL_LogError(0, "element 'tilesets' should be of type array");
        return;
    }

    for (const auto& t : tilesets) {
        this->tiles.push_back(AssetManager::loadSingleTexture(t["source"],renderer));
    }

    // load layer (only one for now)

    auto layers = data["layers"];

    if (!layers.is_array()) {
        SDL_LogError(0, "element 'layers' should be of type array");
        return;
    }

    for (const auto& l: layers) {
        for (const auto& i : l["data"]) {
            this->tileMap.push_back(i);
        }
    }

    SDL_Log("%d",this->tiles.size());

    input.close();

}

int World::getWidth()
{
    return this->wSize;
}

int World::getHeight()
{
    return this->hSize;
}

std::vector<SDL_Texture*>& World::getTiles()
{
    return this->tiles;
}

std::vector<int>& World::getMap()
{
    return this->tileMap;
}