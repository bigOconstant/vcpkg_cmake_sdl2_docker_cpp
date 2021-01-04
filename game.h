#include <iostream>
#include <exception>
#include "board.h"

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