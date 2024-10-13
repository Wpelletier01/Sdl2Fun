#include "asset_manager.h"


int AssetManager::init(SDL_Renderer* renderer) {

    int imgFlag = IMG_INIT_PNG | IMG_INIT_JPG;

    if (IMG_Init(imgFlag) == 0) {
        SDL_LogError(1,"Couldn't initialise image module");
        return 1;
    }

    this->playerSprite = loadingTexture("assets/image/player.png");

    return 0;
}


SDL_Texture* AssetManager::loadTexture(const char* img, SDL_Renderer* renderer) {

    SDL_Texture* loadingTexture = NULL;

    SDL_Surface* loadSurface = IMG_Load(img);

    if (loadSurface == NULL) {
        printf("Couldn't load img '%s'. Error: %s",img,SDL_GetError());
        return NULL;
    }

    loadingTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
    SDL_FreeSurface(loadSurface);

    return loadingTexture;
}
