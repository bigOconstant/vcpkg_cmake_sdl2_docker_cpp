#include "player.h"
#include "primitives.h"


Player::Player(int width) {
    posx = 0;
    posy = 0;
    radius = ((width/15)/2) -10;
};

void Player::draw(SDL2pp::Renderer &input) {
    //B->drawCircle(renderer,posx,posy,((width /15)/2)-10);
    Primitives::drawCircle(input, posx, posy,radius);
};
void Player::setPosition(int x,int y) {
    posx = x;
    posy = y;
};