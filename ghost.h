#include <SDL2pp/SDL2pp.hh>
#include "primitives.h"
class Ghost {
    private:
        int posx;
        int posy;
        int rectwidth;
        int rectHeight;        
    public:
        Ghost(int width);
        //void draw(SDL2pp::Renderer &input);
        Primitives::Direction direction;
        void draw(SDL2pp::Renderer &input);

        void setPosition(int x,int y);
};