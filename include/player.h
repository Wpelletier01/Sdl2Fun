#pragma once

#include <SDL2/SDL.h>
#include "drawable.h"

class Player: public Drawable {

    public:
        Player(std::string sTexture); 

};