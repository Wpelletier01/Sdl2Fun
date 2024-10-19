#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>
#include "entt/entt.hpp"
#include "component.h"

class InputSystem 
{
    public:

        InputSystem();

        void handleKeyInput(SDL_KeyboardEvent key_event);
        void update(entt::registry& registry);
        void clear();

    private:

        // press = true
        std::unordered_map<SDL_Keycode,bool> keyMap;
        

};