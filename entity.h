
#ifndef ENTITY_H
#define ENTITY_H


#include <SDL2pp/SDL2pp.hh>

#include "primitives.h"

class Entity {
   public:
      virtual void draw(SDL2pp::Renderer &input) = 0;
      Entity();
      void setPosition(int x,int y);
      Primitives::Direction direction;

   protected:
      int posx;
      int posy;
};

#endif