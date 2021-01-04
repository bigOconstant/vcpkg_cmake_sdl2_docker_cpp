#include "player.h"

Player::Player(int width) {
    
    radius = ((width/15)/2) -20;
    posx = radius;
    posy = radius;
    direction = Primitives::Direction::right;

};



void Player::draw(SDL2pp::Renderer &input) {
    SDL2pp::Color yellow = SDL2pp::Color(194,198,0);
    Primitives::drawSmoothCircle(input,posx,posy,radius,yellow);
    switch (direction)
    {
        case (Primitives::Direction::right)/* constant-expression */: {
            drawRight(input);
            break;
        }
        case (Primitives::Direction::left)/* constant-expression */: {
            drawLeft(input);
            break;
        }
        case (Primitives::Direction::up)/* constant-expression */: {
            drawUp(input);
            break;
        }
        case (Primitives::Direction::down)/* constant-expression */: {
            drawdown(input);
            break;
        }
       
    
    default:
        break;
    }
    
};

void Player::drawRight(SDL2pp::Renderer &input) {
     Primitives::filledCircleRGBA(input,posx+3,posy-12,radius/5,SDL2pp::Color(255,255,255));
    Primitives::filledCircleRGBA(input,posx+3,posy-12,radius/7,SDL2pp::Color(0,0,0));
    Primitives::filledPieRGBA(input,posx,posy,radius+2, 315, 45, SDL2pp::Color(0,0,0));

};
void Player::drawLeft(SDL2pp::Renderer &input){
   Primitives::filledCircleRGBA(input,posx+3,posy-12,radius/5,SDL2pp::Color(255,255,255));
   Primitives::filledCircleRGBA(input,posx+3,posy-12,radius/7,SDL2pp::Color(0,0,0));
   Primitives::filledPieRGBA(input,posx,posy,radius+2,135 ,225, SDL2pp::Color(0,0,0));
};
void Player::drawUp(SDL2pp::Renderer &input){
    
    
    Primitives::filledPieRGBA(input,posx,posy,radius+2, 225, 315, SDL2pp::Color(0,0,0));
    Primitives::filledCircleRGBA(input,posx+13,posy-6,radius/5,SDL2pp::Color(255,255,255));
    Primitives::filledCircleRGBA(input,posx+13,posy-6,radius/7,SDL2pp::Color(0,0,0));
};
void Player::drawdown(SDL2pp::Renderer &input){
   Primitives::filledCircleRGBA(input,posx+8,posy-3,radius/5,SDL2pp::Color(255,255,255));
   Primitives::filledCircleRGBA(input,posx+8,posy-3,radius/7,SDL2pp::Color(0,0,0));
   Primitives::filledPieRGBA(input,posx,posy,radius+2,45,135, SDL2pp::Color(0,0,0));
};




void Player::setPosition(int x,int y) {
    posx = x;
    posy = y;
};