#include "drawable.h"


Drawable::Drawable(std::string texture) 
{
    SDL_Rect src;
    SDL_Rect dst;

    src.x = 0;
    src.y = 0;
    src.w = 0;
    src.h = 0;

    dst.x = 0;
    dst.y = 0;
    dst.w = 0;
    dst.h = 0;

    this->texture = texture; 
    this->src = src;
    this->dst = dst;
}


SDL_Rect* Drawable::getSource() 
{
    return &this->src;
}

SDL_Rect* Drawable::getDestination()
{
    return &this->dst;
}

std::string Drawable::getTexture()
{
    return this->texture;
}

void Drawable::setTexture(std::string texture)
{
    this->texture = texture;
}

void Drawable::changeSize(int w, int h)
{
    this->dst.w = w;
    this->dst.h = h;
    this->src.w = w;
    this->src.h = h;
} 

void Drawable::updateDest(int x, int y)
{
    this->dst.x = x;
    this->dst.y = y;
} 

void Drawable::updateSrc(int x, int y)
{
    this->src.x = x;
    this->src.y = y;
} 