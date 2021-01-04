#include <SDL2pp/SDL2pp.hh>
#include "primitives.h"
class Player {
    private:
        int radius;
        int posx;
        int posy;
         void drawRight(SDL2pp::Renderer &input);
        void drawLeft(SDL2pp::Renderer &input);
        void drawUp(SDL2pp::Renderer &input);
        void drawdown(SDL2pp::Renderer &input);
        

    public:
        Player(int width);
        void draw(SDL2pp::Renderer &input);
        Primitives::Direction direction;

        void setPosition(int x,int y);
};