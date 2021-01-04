#include <SDL2pp/SDL2pp.hh>
#include "primitives.h"
#include "entity.h"
class Player : public Entity {
    private:
        int radius;
        void drawRight(SDL2pp::Renderer &input);
        void drawLeft(SDL2pp::Renderer &input);
        void drawUp(SDL2pp::Renderer &input);
        void drawdown(SDL2pp::Renderer &input);
        
    public:
        Player(int width);
        void draw(SDL2pp::Renderer &input);    
};