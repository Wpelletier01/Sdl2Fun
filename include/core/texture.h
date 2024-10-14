#pragma once


#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <filesystem>
		
namespace fs = std::filesystem;

class Texture {

    public:

        Texture(fs::path fpath, SDL_Renderer* renderer);
        ~Texture();

        SDL_Texture* mtexture = NULL;

};