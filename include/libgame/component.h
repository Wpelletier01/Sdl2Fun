#pragma once

#include <SDL2/SDL.h>
#include <string>


struct Rect
{
    SDL_Rect val;
};

struct Texture 
{   
    std::string id;
    SDL_Rect src;  
};