#include "player.h"


Player::Player(std::string sTexture) : Drawable(sTexture)
{    

    this->changeSize(400,400);
    this->updateDest(0,0);

}