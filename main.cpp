// main.cpp
#include <sqlite3.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <exception>
#include <SDL2pp/SDL2pp.hh>
using std::cout;
using std::endl;

using namespace SDL2pp;
/* Build manually with,
mkdir build
cd build
cmake ..
make
 */

void drawCircle(SDL2pp::Renderer &input, int x,int y,int radius){
	int startx = x - radius;
	if (startx < 0){
		startx = 0;
	}
	int starty = y - radius;
	if (starty < 0){
		starty = 0;
	}
	for(int i = startx; i < x + radius; ++i) {
		for(int j = starty; j < y + radius; ++j) {
			auto izero = i - x;
			auto jzero = j -y;
			auto destination = ((izero*izero) + (jzero*jzero)) - (radius * radius);
			if(destination <= 0){
				input.DrawPoint(i,j);
			}
		}

	}

	
}

int main() {
try {
    cout<<"starting app"<<endl;
    cout<< sqlite3_libversion()<<endl;

    
   	SDL sdl(SDL_INIT_VIDEO);
	
	// Create main window: 640x480 dimensions, resizable, "SDL2pp demo" title
	Window window("Blah Blah Blah",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			640, 480,
			SDL_WINDOW_RESIZABLE);

	// Create accelerated video renderer with default driver
	Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	auto running = true;
	auto posx = 0;
	SDL_Event e;
	auto start = SDL_GetTicks();
	auto mover = 1;
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
			
			//std::cout<<ticks<<endl;

		}

			auto ticks = SDL_GetTicks();
			if ((ticks - start) > 50){
				posx = posx +mover;
				start = ticks;
				if (posx > 479 || posx <0) {
					mover = mover * -1;
					
				}
			}
			// Load sprites image as a new texture
			SDL2pp::Point start,end;
			start.SetX(0);
			start.SetY(10);

			start.SetX(posx);
			start.SetY(10);
			

			SDL2pp::Color c = SDL2pp::Color(0,0,0);
			renderer.SetDrawColor(c);
			renderer.Clear();

			c = SDL2pp::Color(255,255,255);
			renderer.SetDrawColor(c);
			renderer.DrawLine(10,0,10,posx);

			drawCircle(renderer,50,50,20);

			
			
			
			
			

			// Clear screen
			



			// Show rendered frame
			renderer.Present();
	 
	}
	// 5 second delay
	//SDL_Delay(10000);
} catch (std::exception& e) {
	// If case of error, print it and exit with error
	std::cerr << e.what() << std::endl;
	return 1;
}
	// Here all resources are automatically released and library deinitialized
	return 0;
}