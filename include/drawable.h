#pragma once

#include <SDL2/SDL.h>
#include <string>

class Drawable {

    public:
        
        Drawable(std::string texture);
        
        SDL_Rect* getSource();
        SDL_Rect* getDestination();

        void setTexture(std::string texture);
        void changeSize(int w, int h);
        void updateDest(int x, int y);
        void updateSrc(int x, int y);
        std::string getTexture();
    private:
        SDL_Rect src,dst;
        std::string texture;



};