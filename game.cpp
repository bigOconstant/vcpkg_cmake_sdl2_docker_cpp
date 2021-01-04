#include "game.h"
#include "player.h"
#include "ghost.h"
#include "primitives.h"
#include <SDL2pp/SDL2pp.hh>

//#include "iostream"

Game::Game(){
    // width = 768;
    // height = 480;
      width = 1280;
     height = 720;
    B = new Board(width,height);
};
Game::~Game(){
    delete B;
};

void Game::run() {
    using std::cout;
    using std::endl;
   // using namespace SDL2pp;
	Player *Pacman = new Player(width);
	Ghost *ghost = new Ghost(width);
	auto point = B->getMidPointOfCell(3,0);
	Pacman->setPosition(point.x,point.y);

	point = B->getMidPointOfCell(3,4);
	ghost->setPosition(point.x,point.y);
    cout<<"Running game"<<endl;
    try {

    SDL2pp::SDL sdl(SDL_INIT_VIDEO);
	
	// Create main window: 640x480 dimensions, resizable, "SDL2pp demo" title
	SDL2pp::Window window("Blah Blah Blah",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_RESIZABLE);
			//SDL_WINDOW_FULLSCREEN);
	
    SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	auto running = true;
	auto posx = 175;
	auto posy = 255;
	SDL_Event e;
	auto start = SDL_GetTicks();
	auto mover = 2;
	while (running) {
		while(SDL_PollEvent(&e) != 0) {
			//
			auto ms = SDL_GetTicks();
		//User requests quit
			if( e.type == SDL_QUIT )
			{
				running = false;
			}
			else if (e.type == SDL_KEYDOWN ){
				if(e.key.keysym.sym == SDLK_ESCAPE){
					cout<<"exiting"<<endl;
					running = false;
				}else if(e.key.keysym.sym == SDLK_UP) {
					Pacman->direction = Primitives::Direction::up;
				}
				else if(e.key.keysym.sym == SDLK_LEFT) {
					Pacman->direction = Primitives::Direction::left;
				}
				else if(e.key.keysym.sym == SDLK_RIGHT) {
					Pacman->direction = Primitives::Direction::right;
				}
				else if(e.key.keysym.sym == SDLK_DOWN) {
					Pacman->direction = Primitives::Direction::down;
				}
			}else if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                SDL_GetMouseState(&posx,
                         &posy);
                auto P = B->GetCellForXAndY(posx,posy);
                if (P.OnGrid){
				    Pacman->setPosition(posx,posy);
                }
                cout<<"cell row:"<<P.row<< " cell col:"<<P.col<<endl;
                cout<<"x:"<<posx<<" y:"<<posy<<endl;
               
            }

		}


			SDL2pp::Color c = SDL2pp::Color(0,0,0);
			renderer.SetDrawColor(c);
			renderer.Clear();

			c = SDL2pp::Color(255,255,255);
			renderer.SetDrawColor(c);
			Pacman->draw(renderer);
			ghost->draw(renderer);
			//B->drawCircle(renderer,posx,posy,((width /15)/2)-10);
			renderer.SetDrawColor(c);
			B->drawGrid(renderer);
			
			auto ticks = SDL_GetTicks();
			
			renderer.Present();
			height = window.GetHeight();
			width = window.GetWidth();
	
	}

    } catch (std::exception& e) {
        // If case of error, print it and exit with error
        std::cerr << e.what() << std::endl;
    }
	delete Pacman;
}