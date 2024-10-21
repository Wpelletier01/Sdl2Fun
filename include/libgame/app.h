#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

#include "asset_manager.h"
#include "renderer.h"
#include "entity_manager.h"
#include "component.h"
#include "world.h"
#include "system/input.h"
#include "system/movement.h"
#include "entt/entt.hpp"



class App {

    public:

        int init(int width, int height, const char* title);

        ~App();

        void run();


    private:

        void movePlayer(entt::entity player, entt::registry* registry);
        void handleEvent(SDL_Event* event);
        void update(entt::entity player);
        void render(World* world);
        
        bool running = false;
        SDL_Window *window = NULL;
        
        Renderer renderer;  
        EntityManager entityManager;      
        // system
        Input inputSys;
        Movement moveSys;
};