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
	SDL2pp::Color yellow = SDL2pp::Color(226,132,14);
	int startx = x - radius;
	if (startx < 0){
		startx = 0;
	}
	int starty = y - radius;
	if (starty < 0){
		starty = 0;
	}
	/* Loop over a square of possible pixils */
	for(int i = startx; i < x + radius; ++i) {
		for(int j = starty; j < y + radius; ++j) {
			auto izero = i - x;
			auto jzero = j - y;
			// Basic circle drawing algorithm.
			auto destination = ((izero*izero) + (jzero*jzero)) - (radius * radius);
			
			/* If less than zero in circle, if zero on paremeter, if greator than zero not in circle */
			if(destination <= 0) {
				input.SetDrawColor(yellow);
				input.DrawPoint(i,j);
			}
		}

	}
}

void drawGrid(SDL2pp::Renderer &input,int width,int height) {
	int w = width /15;
	for (int i = 2; i < 13; ++i){
		input.DrawLine(w * i,w,w * i,w * 8);
	}

	for(int i = w; i <= height; i = i + w){
		input.DrawLine(w*2,i,12 * w,i);
	}

}

int main() {
try {
    cout<<"starting app"<<endl;
    cout<< sqlite3_libversion()<<endl;
	int width = 1280;
	int height = 720;
    
   	SDL sdl(SDL_INIT_VIDEO);
	
	// Create main window: 640x480 dimensions, resizable, "SDL2pp demo" title
	Window window("Blah Blah Blah",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_RESIZABLE);

	// Create accelerated video renderer with default driver
	Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
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
			
			//std::cout<<ticks<<endl;

		}

			auto ticks = SDL_GetTicks();
			if ((ticks - start) > 50){
				posx = posx +mover;
				start = ticks;
				if (posx > 720 || posx <0) {
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

			drawCircle(renderer,posx,60,((width /15)/2)-10);
			renderer.SetDrawColor(c);
			drawGrid(renderer, width, height);

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