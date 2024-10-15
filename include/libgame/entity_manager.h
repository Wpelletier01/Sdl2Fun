#pragma once

#include "component.h"
#include "entt/entt.hpp"


class EntityManager 
{

    public:
        
        entt::entity createPlayer(
            Position pos, 
            Size size,
            std::string texId, 
            Position texSrcPos 
        );

        entt::registry* getRegistry();

    private:
        entt::registry registry;

};