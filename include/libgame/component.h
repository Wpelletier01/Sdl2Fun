#pragma once

#include <SDL2/SDL.h>
#include <string>

struct Position 
{
    int x;
    int y;
};

struct Size
{
    int w;
    int h;
};

struct Drawable 
{   
    std::string textureId;
    SDL_Rect src;
    SDL_Rect dst;   
};