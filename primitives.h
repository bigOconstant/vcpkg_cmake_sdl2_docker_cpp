
#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <SDL2pp/SDL2pp.hh>

namespace Primitives {
    enum class Direction { 
        up = 1,
        down = 2,
        left = 3,
        right = 4 
    };


    void drawCircle(SDL2pp::Renderer &input, int x,int y,int radius); 
}

#endif