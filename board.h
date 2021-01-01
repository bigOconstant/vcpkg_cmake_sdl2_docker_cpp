

#include <SDL2pp/SDL2pp.hh>
#include "primitives.h"
struct Cell {
    bool north;
    bool south;
    bool east;
    bool west;

    Cell() {
        north = false,south = false,east = false,west = false;
    }
};
struct Point {
    int row;
    int col;
    bool OnGrid;
};
class Board {
    private:
        Cell **board;
        int rowCount;
        int columnCount;
        int width;
        int height;

    public:
        Board(int w, int h){
            width = w;
            height = h;
            rowCount = 7;
            columnCount = 10;
            board = new Cell*[rowCount];
            for(int i = 0; i < rowCount; ++i){
                board[i] = new Cell[columnCount];
            }
        }

        ~Board() {
            for(int i = 0; i < rowCount; ++i) {
                delete board[i];
            }
            delete board;
        }
        
        void drawGrid(SDL2pp::Renderer &input);
        Point GetCellForXAndY(int x, int y);
        void drawSinglecell(SDL2pp::Renderer &input,int row,int col,int thickness,Primitives::Direction direction);

};