#include "entity_manager.h"


entt::entity EntityManager::createPlayer(
    Position pos, 
    Size size,
    std::string texId, 
    Position texSrcPos)
{

    entt::entity entity = this->registry.create();

    this->registry.emplace<Position>(entity,pos.x,pos.y);
    this->registry.emplace<Size>(entity, size.w, size.h);
    this->registry.emplace<Drawable>(
        entity,
        texId,
        SDL_Rect{texSrcPos.x,texSrcPos.y,size.w,size.h},
        SDL_Rect{pos.x, pos.y, size.w, size.h}
    );

    return entity;
}


entt::registry* EntityManager::getRegistry()
{
    return &this->registry;
}