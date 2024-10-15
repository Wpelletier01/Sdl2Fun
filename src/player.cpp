#include "player.h"


Player::Player(std::string sTexture) : Drawable(sTexture)
{    

    this->changeSize(128,128);
    this->updateSrc(0,0);
    this->updateDest(200,200);

}