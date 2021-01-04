
#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <SDL2pp/SDL2pp.hh>

/*

Primitives is to be a mapper for SDL2_gfxPrimitives to cpp functions that use SDLPP types instead of the default sdl2 types.

*/

namespace Primitives {
    enum class Direction { 
        up = 1,
        down = 2,
        left = 3,
        right = 4 
    };

    struct Location{
        int x;
        int y;
    };


    void drawSmoothCircle(SDL2pp::Renderer &input, int x,int y,int radius,SDL2pp::Color color);
    void filledCircleRGBA(SDL2pp::Renderer &input, int x,int y,int radius,SDL2pp::Color color);
    void filledPieRGBA(SDL2pp::Renderer &input,Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, SDL2pp::Color color);
    void filledEllipseRGBA(SDL2pp::Renderer &input, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry,SDL2pp::Color color);
}

#endif