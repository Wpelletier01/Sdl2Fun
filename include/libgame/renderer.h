#pragma once

#include <map>
#include <SDL2/SDL.h>
#include <string>
#include "asset_manager.h"
#include "component.h"
#include "entt/entt.hpp"

class Renderer {

    public:
        int init(SDL_Window* win, entt::registry* registry);

        ~Renderer();

        void clear();
        void renderAll();
        void present();

    private:
        SDL_Renderer* mrenderer;
        entt::registry* mregistry;
        std::map<std::string,SDL_Texture*> textures;

};