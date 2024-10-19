#include "entity_manager.h"


entt::entity EntityManager::createEntity()
{
    return this->registry.create();
}

void EntityManager::deleteEntity(entt::entity entity)
{
    this->registry.destroy(entity);
}


void EntityManager::addRectComponent(entt::entity entity, int sx, int sy, int sw, int sh)
{
    this->registry.emplace<Rect>(entity, SDL_Rect{sx,sy,sw,sh});
}

void EntityManager::addTextureComponent(entt::entity entity, std::string texId, int x, int y, int w, int h)
{
    this->registry.emplace<Texture>(entity,Texture{texId,SDL_Rect{x,y,w,h}});
}

void EntityManager::addMoveSpeedComponent(entt::entity entity, float speed)
{
    this->registry.emplace<MoveSpeed>(entity,MoveSpeed{speed});
}

void EntityManager::addInputComponent(entt::entity entity)
{
    // add keyboard and mouse input
    this->registry.emplace<KeyboardInput>(entity,KeyboardInput());
}


entt::registry* EntityManager::getRegistry()
{
    return &this->registry;
}