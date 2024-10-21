#pragma once

#include "entt/entt.hpp"


class System 
{
    public:
        virtual void update(entt::registry* registry) = 0;
};