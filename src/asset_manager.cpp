#include "asset_manager.h"





int AssetManager::init() {

    int imgFlag = IMG_INIT_PNG | IMG_INIT_JPG;

    if (IMG_Init(imgFlag) == 0) {
        SDL_LogError(1,"Couldn't initialise image module");
        return 1;
    }




    return 0;
}
