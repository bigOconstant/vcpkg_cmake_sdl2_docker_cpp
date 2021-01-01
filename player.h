#include <SDL2pp/SDL2pp.hh>
#include "primitives.h"
class Player {
    private:
        int radius;
        int posx;
        int posy;
        Primitives::Direction direction;

    public:
        Player(int width);
        void draw(SDL2pp::Renderer &input);
        void setPosition(int x,int y);
};