#include "system/input.h"


void Input::handleKeyInput(SDL_KeyboardEvent kevent)
{
    keyMap[kevent.keysym.sym] = (kevent.state != SDL_KEYUP);
}


void Input::update(entt::registry* registry)
{
    auto view = registry->view<KeyboardInput>();

    for (auto entity : view) {
        auto& input = view.get<KeyboardInput>(entity);
        input.keys = this->keyMap;
    }

}

void Input::clear()
{
    this->keyMap.clear();
}
