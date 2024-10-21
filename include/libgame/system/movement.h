#pragma once

#include <SDL2/SDL.h>
#include "system/system.h"
#include "component.h"
#include "entt/entt.hpp"

class Movement : public System
{
    public:

        void update(entt::registry* registry);
    
    private:

        void byInput(entt::registry* registry);

};