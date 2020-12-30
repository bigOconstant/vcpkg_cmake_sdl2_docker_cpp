 #include "board.h"

 void Board::drawGrid(SDL2pp::Renderer &input,int width,int height) {
            int w = width /15;
            for (int i = 2; i < 13; ++i){
                input.DrawLine(w * i,w,w * i,w * 8);
            }

            for(int i = w; i <= height; i = i + w){
                input.DrawLine(w*2,i,12 * w,i);
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