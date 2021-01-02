#include "player.h"

Player::Player(int width) {
    
    radius = ((width/15)/2) -20;
    posx = radius;
    posy = radius;
};

void Player::draw(SDL2pp::Renderer &input) {
    SDL2pp::Color yellow = SDL2pp::Color(226,132,14);
    Primitives::drawSmoothCircle(input,posx,posy,radius,yellow);
    Primitives::filledCircleRGBA(input,posx+5,posy-12,radius/5,SDL2pp::Color(255,255,255));
    Primitives::filledCircleRGBA(input,posx+5,posy-12,radius/7,SDL2pp::Color(0,0,0));
    Primitives::filledPieRGBA(input,posx,posy,radius+2, -25, 30, SDL2pp::Color(0,0,0));
};

void Player::setPosition(int x,int y) {
    posx = x;
    posy = y;
    direction = Primitives::Direction::right;
};