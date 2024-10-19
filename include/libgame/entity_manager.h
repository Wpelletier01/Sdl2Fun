#pragma once

#include "component.h"
#include "entt/entt.hpp"


class EntityManager 
{

    public:

        entt::entity createEntity();
        void deleteEntity(entt::entity entity);


        void addRectComponent(entt::entity entity, int sx, int sy, int sw, int sh);
        void addTextureComponent(entt::entity entity, std::string texId, int x, int y, int w, int h);


        entt::registry* getRegistry();

    private:
        entt::registry registry;

};