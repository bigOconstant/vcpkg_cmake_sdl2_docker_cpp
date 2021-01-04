
#include "ghost.h"

Ghost::Ghost(int width) {
    posx = 100;
    posy = 100;
    rectwidth = 30;
    rectHeight = 15;
    direction = Primitives::Direction::right;
};

void Ghost::draw(SDL2pp::Renderer &input) {
    SDL2pp::Color yellow = SDL2pp::Color(194,198,0);
    SDL2pp::Color red = SDL2pp::Color(251,0,23);
    //Primitives::drawSmoothCircle(input,posx,posy,radius,yellow);
    SDL2pp::Rect R(posx - (rectwidth/2),posy,rectwidth+1,rectHeight);
    input.SetDrawColor(red);
    input.FillRect(R);
    input.SetDrawColor(red);
    Primitives::filledCircleRGBA(input,posx,posy,15,red);

    input.SetDrawColor(red);
    Primitives::filledEllipseRGBA(input,posx-10,posy+12,5,14,red);
    Primitives::filledEllipseRGBA(input,posx,posy+12,5,14,red);
    Primitives::filledEllipseRGBA(input,posx+10,posy+12,5,14,red);


    Primitives::filledEllipseRGBA(input,posx+7,posy-4,4,6,SDL2pp::Color(255,255,255));
    Primitives::filledCircleRGBA(input,posx+7,posy-4,3,SDL2pp::Color(0,0,0));

    Primitives::filledEllipseRGBA(input,posx-7,posy-4,4,6,SDL2pp::Color(255,255,255));
    Primitives::filledCircleRGBA(input,posx-7,posy-4,3,SDL2pp::Color(0,0,0));
};
