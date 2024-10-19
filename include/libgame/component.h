#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>

struct Rect
{
    SDL_Rect val;
};

struct Texture 
{   
    std::string id;
    SDL_Rect src;  
};

struct KeyboardInput
{
    std::unordered_map<SDL_Keycode,bool> keys;
};