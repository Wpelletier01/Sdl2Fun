#include "world.h"

World::World(std::string worldDir, SDL_Renderer* renderer)
{   
    fs::path config = fs::path(worldDir) / "test.json";

    this->tiles.push_back(NULL);

    std::ifstream input(config);

    if (!input.is_open()) {
        SDL_LogError(0, "couldn't open tilemap '%s'",config.c_str());
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
        this->tiles.push_back(AssetManager::loadSingleTexture(fs::path(worldDir) / t["source"],renderer));
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