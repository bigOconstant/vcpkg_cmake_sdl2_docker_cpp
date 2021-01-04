#include "primitives.h"   
#include "SDL2_gfxPrimitives.h" 

    void Primitives::drawSmoothCircle(SDL2pp::Renderer &input, int x,int y,int radius,SDL2pp::Color color){
        int startx = x - radius;
        if (startx < 0){
            startx = 0;
        }
        int starty = y - radius;
        if (starty < 0){
            starty = 0;
        }
        /* Loop over a square of possible pixils This circle is smoother than the gfx Library does */
        for(int i = startx; i < x + radius; ++i) {
            for(int j = starty; j < y + radius; ++j) {
                auto izero = i - x;
                auto jzero = j - y;
                // Basic circle drawing algorithm.
                auto destination = ((izero*izero) + (jzero*jzero)) - (radius * radius);
                
                /* If less than zero in circle, if zero on paremeter, if greator than zero not in circle */
                if(destination <= 0) {
                    input.SetDrawColor(color);
                    input.DrawPoint(i,j);
                }
            }

         }
    }

    void Primitives::filledCircleRGBA(SDL2pp::Renderer &input, int x,int y,int radius,SDL2pp::Color color){
        filledCircleRGBA(input.Get(),x,y,radius,color.r,color.g,color.b,color.a);
    }

    void Primitives::filledPieRGBA(SDL2pp::Renderer &input,Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, SDL2pp::Color color){
        filledPieRGBA(input.Get(), x,y,rad, start, end, color.r,color.g,color.b,color.a);
    }

    void Primitives::filledEllipseRGBA(SDL2pp::Renderer &input, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry,SDL2pp::Color color){
        filledEllipseRGBA(input.Get(),x,y,rx,ry,color.r,color.g,color.b,color.a);
    }

