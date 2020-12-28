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

int main() try {

    cout<<"starting app"<<endl;
    cout<< sqlite3_libversion()<<endl;

    nlohmann::json j;
   SDL sdl(SDL_INIT_VIDEO);

	// Create main window: 640x480 dimensions, resizable, "SDL2pp demo" title
	Window window("Blah Blah Blah",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			640, 480,
			SDL_WINDOW_RESIZABLE);

	// Create accelerated video renderer with default driver
	Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Load sprites image as a new texture
	SDL2pp::Point start,end;
	start.SetX(0);
	start.SetY(10);

	start.SetX(400);
	start.SetY(10);
	
	SDL2pp::Color c(255,255,255);
	renderer.SetDrawColor(c);
	renderer.DrawLine(10,0,10,640);

	// Clear screen
	//renderer.Clear();



	// Show rendered frame
	renderer.Present();

	// 5 second delay
	SDL_Delay(10000);

	// Here all resources are automatically released and library deinitialized
	return 0;
} catch (std::exception& e) {
	// If case of error, print it and exit with error
	std::cerr << e.what() << std::endl;
	return 1;
}