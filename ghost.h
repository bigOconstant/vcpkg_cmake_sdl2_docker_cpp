#include <SDL2pp/SDL2pp.hh>
#include "primitives.h"
#include "entity.h"
class Ghost: public Entity {
    private:
        int rectwidth;
        int rectHeight;        
    public:
        Ghost(int width);
        //void draw(SDL2pp::Renderer &input);
        Primitives::Direction direction;
        void draw(SDL2pp::Renderer &input);

};