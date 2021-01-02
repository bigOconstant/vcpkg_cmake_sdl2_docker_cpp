#include "board.h"
void Board::SetLevelBarriers(){

	board[0][0].west = true;
	board[1][0].west = true;
	board[2][0].west = true;

	//board[2][0].south = true;
	//board[4][0].north = true;

	board[4][0].west = true;
	board[5][0].west = true;
	board[6][0].west = true;

	board[1][1].north = true;
	board[1][2].north = true;

	board[1][4].north = true;
	board[1][5].north = true;

	board[1][7].north = true;
	board[1][8].north = true;

	board[2][1].north = true;
	board[2][2].north = true;

	board[2][4].north = true;
	board[2][5].north = true;

	board[2][7].north = true;
	board[2][8].north = true;

	board[2][1].east = true;
	board[2][2].west = true;

	board[2][7].east = true;
	board[2][8].west = true;


	//
	board[4][0].east = true;
	board[5][0].east = true;

	board[5][1].south = true;
	board[5][2].south = true;

	board[4][1].east = true;
	board[4][2].south = true;

	// board[3][5].east = true;
	// board[3][6].east = true;

	board[5][3].east = true;
	board[6][3].east = true;

	board[4][4].east = true;
	board[5][4].east = true;

	board[5][5].east = true;
	board[6][5].east = true;

	board[4][8].east = true;
	board[5][8].east = true;
	board[5][8].south = true;
	board[5][7].south = true;


	board[4][7].east = true;
	board[4][7].south = true;

	board[3][4].west = true;
	board[3][4].south = true;

	board[3][5].south = true;
	board[3][5].east = true;

	for(int i = 0; i < columnCount; ++i){
        board[0][i].north = true;
 	}
	 for(int i = 0; i < columnCount; ++i){
        board[rowCount -1][i].south = true;
 	}

	 for(int i = 0; i < rowCount; ++i) {
		 if(i != 3){
        	board[i][columnCount -1].east = true;
		 }
 	}


}
 void Board::drawGrid(SDL2pp::Renderer &input) {
            int w = width /17;
			auto startingPixelLeft = width /5;
			auto endingPixelRight =  startingPixelLeft + (w*10);//width - startingPixelLeft;
			auto startingPixelTop = height / 5;

			SDL2pp::Color white = SDL2pp::Color(255,255,255);
			input.SetDrawColor(white);

			// for(auto i = 0; i <= 7; ++i) {
			// 	input.DrawLine(startingPixelLeft,(i * w)+startingPixelTop ,endingPixelRight,(i*w)+startingPixelTop);
			// }

			// for(auto i = 0; i <=10; ++i){
			// 	input.DrawLine(startingPixelLeft+(i*w),startingPixelTop,startingPixelLeft+(i*w),(7*w)+startingPixelTop);
			// }

			drawboarders(input);
        };

void Board::drawboarders(SDL2pp::Renderer &input){
	 for(int i = 0; i < rowCount; ++i){
        for(int j = 0; j < columnCount; ++j){
			if(board[i][j].west){
				drawSinglecell(input,i,j,2,Primitives::Direction::left);
			}
			if(board[i][j].east){
				drawSinglecell(input,i,j,2,Primitives::Direction::right);
			}
			if(board[i][j].south){
				drawSinglecell(input,i,j,2,Primitives::Direction::down);
			}
			if(board[i][j].north){
				drawSinglecell(input,i,j,2,Primitives::Direction::up);
			}
		}           
	 }
}

		
void Board::drawSinglecell(SDL2pp::Renderer &input,int row,int col,int thickness,Primitives::Direction direction){
	int w = width /17;
	auto startingPixelLeft = width /5;
	auto startingPixelTop = height / 5;

	// Draw Top Line
	SDL2pp::Color blue = SDL2pp::Color(65,75,186);
	input.SetDrawColor(blue);

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

	point.row = ymapped / w;
	point.col = xmapped / w;

	if(point.row > 6){
		point.OnGrid = false;
		return point;
	}
	if(point.col > 9){
		point.OnGrid = false;
		return point;
	}
	point.OnGrid = true;
	return point;
 };

//Todo Not Finished
 Primitives::Location Board::getMidPointOfCell(int row,int col){
	Primitives::Location location;
	location.x = 0;
	location.y = 0;

	int w = width /17;
	auto startingPixelLeft = width /5;
	auto startingPixelTop = height / 5;

	return location;
 }
