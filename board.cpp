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
        };

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
