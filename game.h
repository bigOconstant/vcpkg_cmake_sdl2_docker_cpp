#include <iostream>
#include <exception>
#include "board.h"
#include <SDL2pp/SDL2pp.hh>

class Game {
    private:
        int height;
        int width;
        Board *B;
    public:
        Game();
        ~Game();
        void run();
};