#include "board.h"

 void Board::drawGrid(SDL2pp::Renderer &input) {
            int w = width /17;
			auto startingPixelLeft = width /5;
			auto endingPixelRight =  startingPixelLeft + (w*10);//width - startingPixelLeft;
			auto startingPixelTop = height / 5;

			SDL2pp::Color white = SDL2pp::Color(255,255,255);
			input.SetDrawColor(white);

			for(auto i = 0; i <= 7; ++i) {
				// input.DrawLine(w + i * startingPixelLeft,startingPixelLeft * 10,w * i,startingPixelLeft);
				input.DrawLine(startingPixelLeft,(i * w)+startingPixelTop ,endingPixelRight,(i*w)+startingPixelTop);
				SDL2pp::Color c = SDL2pp::Color(0,0,0);
			
			}

			for(auto i = 0; i <=10; ++i){
				input.DrawLine(startingPixelLeft+(i*w),startingPixelTop,startingPixelLeft+(i*w),(7*w)+startingPixelTop);
			}

			drawSinglecell(input,2,2,1,Primitives::Direction::down);
			drawSinglecell(input,2,2,1,Primitives::Direction::up);
        };
		
void Board::drawSinglecell(SDL2pp::Renderer &input,int row,int col,int thickness,Primitives::Direction direction){
	int w = width /17;
	auto startingPixelLeft = width /5;
	auto startingPixelTop = height / 5;

	// Draw Top Line
	SDL2pp::Color red = SDL2pp::Color(176,24,24);
	input.SetDrawColor(red);

	switch(direction)
	{
		case Primitives::Direction::up  :{
			input.DrawLine(startingPixelLeft+ (w*col),startingPixelTop + w*row,startingPixelLeft+ (w*col+w),startingPixelTop + w*row);

			// Make it thick
			for(auto i = 1; i < thickness ; ++i) {
				input.DrawLine(startingPixelLeft+ (w*col)-i,startingPixelTop + w*row+i,startingPixelLeft+ (w*col+w)+i,startingPixelTop + w*row+i);
				input.DrawLine(startingPixelLeft+ (w*col)-i,startingPixelTop + w*row-i,startingPixelLeft+ (w*col+w) +i,startingPixelTop + w*row-i);
			}
			break;
		};
		case Primitives::Direction::down: {
				//Draw Bottom
			input.DrawLine(startingPixelLeft+ (w*col),startingPixelTop + w*row +w,startingPixelLeft+ (w*col+w),startingPixelTop + w*row +w);

			// Make it thick
			for(auto i = 1; i < thickness ; ++i) {
				input.DrawLine(startingPixelLeft+ (w*col)-i,startingPixelTop + w*row+i +w,startingPixelLeft+ (w*col+w)+i,startingPixelTop + w*row+i+w);
				input.DrawLine(startingPixelLeft+ (w*col)-i,startingPixelTop + w*row-i +w,startingPixelLeft+ (w*col+w) +i,startingPixelTop + w*row-i +w);
			}
			break;
		};
		case Primitives::Direction::left : {
			// Draw left
			input.DrawLine(startingPixelLeft+ (w*col),startingPixelTop + w*row,startingPixelLeft+ (w*col),startingPixelTop + w*row +w);

			for(auto i = 1; i < thickness ; ++i) {
				input.DrawLine(startingPixelLeft+ (w*col)+i,startingPixelTop + w*row+i,startingPixelLeft+ (w*col)+i,startingPixelTop + w*row +w +i);
				input.DrawLine(startingPixelLeft+ (w*col)-i,startingPixelTop + w*row-i,startingPixelLeft+ (w*col)-i,startingPixelTop + w*row +w -i);
			}
			break;
		};
		case Primitives::Direction::right : {
		//Draw right
			input.DrawLine(startingPixelLeft+ (w*col)+w,startingPixelTop + w*row,startingPixelLeft+ (w*col)+w,startingPixelTop + w*row +w);

			for(auto i = 1; i < thickness ; ++i) {
				input.DrawLine(startingPixelLeft+ (w*col)-i +w,startingPixelTop + w*row+i,startingPixelLeft+ (w*col)-i +w,startingPixelTop + w*row +w +i);
				input.DrawLine(startingPixelLeft+ (w*col)+i +w ,startingPixelTop + w*row-i,startingPixelLeft+ (w*col)+i +w,startingPixelTop + w*row +w -i);
			}
			break;
		};
	}	
	
	

	

	

	
	
}

 Point Board::GetCellForXAndY(int xIn, int yIn) {
	Point point{};
	 
	int w = width /17;
	auto startingPixelLeft = width /5;
	auto startingPixelTop = height / 5;

	if (xIn < startingPixelLeft){
		point.OnGrid = false;
		return point;
	}
	if (yIn < startingPixelTop){
		point.OnGrid = false;
		return point;
	}

	auto xmapped = xIn - startingPixelLeft;
	auto ymapped = yIn - startingPixelTop;

	point.row = xmapped / w;
	point.col = ymapped / w;

	if(point.row > 9){
		point.OnGrid = false;
		return point;
	}
	if(point.col > 6){
		point.OnGrid = false;
		return point;
	}
	point.OnGrid = true;
	return point;
 };
