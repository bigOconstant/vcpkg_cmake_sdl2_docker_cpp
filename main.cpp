// main.cpp

#include <iostream>
#include <exception>
#include <SDL2pp/SDL2pp.hh>
#include "game.h"
using std::cout;
using std::endl;

using namespace SDL2pp;

int main() {
	
	auto game =new Game();
	game->run();

	delete game;
	return 0;
}