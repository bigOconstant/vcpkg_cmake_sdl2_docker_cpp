#include <iostream>
#include <exception>
#include "board.h"
#include <SDL2pp/SDL2pp.hh>

class Game {
    private:
        int height;
        int width;
        std::unique_ptr<Board> B;
    public:
        Game();
        void run();
};