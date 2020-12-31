#include "board.h"

 void Board::drawGrid(SDL2pp::Renderer &input,int width,int height) {
            int w = width /17;
			auto startingPixelLeft = width /5;
			auto endingPixelRight =  startingPixelLeft + (w*10);//width - startingPixelLeft;
			auto startingPixelTop = height / 5;

			for(auto i = 0; i <= 7; ++i) {
				// input.DrawLine(w + i * startingPixelLeft,startingPixelLeft * 10,w * i,startingPixelLeft);
				input.DrawLine(startingPixelLeft,(i * w)+startingPixelTop ,endingPixelRight,(i*w)+startingPixelTop);
			}

			for(auto i = 0; i <=10; ++i){
				input.DrawLine(startingPixelLeft+(i*w),startingPixelTop,startingPixelLeft+(i*w),(7*w)+startingPixelTop);
			}
        }

void Board::drawCircle(SDL2pp::Renderer &input, int x,int y,int radius) {
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