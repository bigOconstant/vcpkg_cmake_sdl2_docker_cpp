#include "player.h"

Player::Player(int width) {
    
    radius = ((width/15)/2) -10;
    posx = radius;
    posy = radius;
};

void Player::draw(SDL2pp::Renderer &input) {
    //B->drawCircle(renderer,posx,posy,((width /15)/2)-10);
    Primitives::drawCircle(input, posx, posy,radius);
};

void Player::setPosition(int x,int y) {
    posx = x;
    posy = y;
    direction = Primitives::Direction::right;
};