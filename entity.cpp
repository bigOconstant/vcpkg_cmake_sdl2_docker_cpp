#include "entity.h"

void Entity::setPosition(int x,int y) {
    posx = x;
    posy = y;
};

Entity::Entity() {
   setPosition(0,0);
   direction = Primitives::Direction::right;
};