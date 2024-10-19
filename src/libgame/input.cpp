#include "input.h"

InputSystem::InputSystem()
{

}

void InputSystem::handleKeyInput(SDL_KeyboardEvent kevent)
{
    keyMap[kevent.keysym.sym] = (kevent.type == SDL_KEYDOWN);
}


void InputSystem::update(entt::registry& registry)
{

    auto view = registry.view<KeyboardInput>();

    for (auto entity : view) {
        auto& input = view.get<KeyboardInput>(entity);
        input.keys = this->keyMap;
    }


}

void InputSystem::clear()
{
    this->keyMap.clear();
}
