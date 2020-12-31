#include "game.h"
//#include "iostream"

Game::Game(){
    width = 1280;
    height = 720;
    B = std::unique_ptr<Board>();
};

void Game::run() {
    using std::cout;
    using std::endl;
   // using namespace SDL2pp;

    cout<<"Running game"<<endl;
    try {

    SDL2pp::SDL sdl(SDL_INIT_VIDEO);
	
	// Create main window: 640x480 dimensions, resizable, "SDL2pp demo" title
	SDL2pp::Window window("Blah Blah Blah",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_RESIZABLE);

    SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	auto running = true;
	auto posx = 0;
	SDL_Event e;
	auto start = SDL_GetTicks();
	auto mover = 2;
	while (running) {
		while(SDL_PollEvent(&e) != 0) {
			auto ms = SDL_GetTicks();
		//User requests quit
			if( e.type == SDL_QUIT )
			{
				running = false;
			}
			else if (e.type == SDL_KEYDOWN ){
				if(e.key.keysym.sym == SDLK_ESCAPE){
					cout<<"blahttt"<<endl;
					running = false;
				}else if(e.key.keysym.sym == SDLK_a) {
					std::cout<<ms<<endl;
				}
			}
		}

			auto ticks = SDL_GetTicks();
			if ((ticks - start) > 50){
				posx = posx +mover;
				start = ticks;
				if (posx > 720 || posx <0) {
					mover = mover * -1;
					
				}
			}

			SDL2pp::Color c = SDL2pp::Color(0,0,0);
			renderer.SetDrawColor(c);
			renderer.Clear();

			c = SDL2pp::Color(255,255,255);
			renderer.SetDrawColor(c);
			renderer.DrawLine(10,0,10,posx);

			B->drawCircle(renderer,posx,60,((width /15)/2)-10);
			renderer.SetDrawColor(c);
			B->drawGrid(renderer, width, height);

			// Show rendered frame
			renderer.Present();
	 
	}
	// 5 second delay
	//SDL_Delay(10000);
    } catch (std::exception& e) {
        // If case of error, print it and exit with error
        std::cerr << e.what() << std::endl;
    }
}