#include <SDL2pp/SDL2pp.hh>

class Player {
    private:
        int radius;
        int posx;
        int posy;

    public:
        Player(int width);
        void draw(SDL2pp::Renderer &input);
        void setPosition(int x,int y);
};