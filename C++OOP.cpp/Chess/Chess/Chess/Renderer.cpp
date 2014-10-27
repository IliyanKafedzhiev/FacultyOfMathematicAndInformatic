#include "Renderer.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"

const char Renderer::textures[6][2][8][9] = {
	{ // pawn
		{"        ","        ","        ","   ++   ","  ++++  ","   ||   ","  ||||  "," |||||| "}, // black
		{"        ","        ","        ","   ##   ","  ####  ","   OO   ","  OOOO  "," OOOOOO "}  // white
	},
	{ // rook
		{"        ","        "," + ++ + "," ++++++ "," |||||| "," |||||| "," |||||| ","||||||||"},
		{"        ","        "," # ## # "," ###### "," OOOOOO "," OOOOOO "," OOOOOO ","OOOOOOOO"}
	},
	{ // knight
		{"     +  ","    ++  ","  +++++ "," ++ ++++","    ++++","   ++++ ","  ++++  "," +++++++"},
		{"     #  ","    ##  ","  ##### "," ## ####","    ####","   #### ","  ####  "," #######"}
	},
	{ // bishop
		{"        ","   ++   ","  ++++  ","   ||   ","   ||   ","   ||   ","  ||||  "," |||||| "},
		{"        ","   ##   ","  ####  ","   OO   ","   OO   ","   OO   ","  OOOO  "," OOOOOO "}
	},
	{ // queen
		{"        "," + ++ + "," ++++++ ","  ||||  ","   ||   ","   ||   ","  ||||  "," |||||| "},
		{"        "," # ## # "," ###### ","  OOOO  ","   OO   ","   OO   ","  OOOO  "," OOOOOO "}
	},
	{ // king
		{"   ++   "," ++++++ ","   ++   ","   ||   ","   ||   ","   ||   ","  ||||  "," |||||| "},
		{"   ##   ","   ##   "," ###### ","  OOOO  ","   OO   ","   OO   ","  OOOO  "," OOOOOO "}
	}
};



Renderer::Renderer(Engine *engine,Board *board): e(engine), b(board) {
	this->selector.row = this->selector.col = 4;
	this->target.row = this->target.col = 3;
}

void Renderer::draw() {
	this->drawBoard();
	this->drawSelector();
	this->drawTarget();
	this->drawFigures();
}

void Renderer::drawTarget() {
	if( this->target.col < 0 || this->target.col > Renderer::_bSize || 
		this->target.row < 0 || this->target.row > Renderer::_bSize )
	return;
	int oTop  = this->target.row * Renderer::_cSize;
	int oLeft = this->target.col * Renderer::_cSize;
	
	(*this->e)(oLeft,oTop,4); // top left
	(*this->e)(oLeft + Renderer::_cSize - 1,oTop,(char)4); // top right
	(*this->e)(oLeft,oTop + Renderer::_cSize - 1,(char)4); // bottom left
	(*this->e)(oLeft + Renderer::_cSize-1,oTop + Renderer::_cSize-1,(char)4); //bottom right

	// top middle
	(*this->e)(oLeft + Renderer::_cSize/2-1,oTop,(char)25);
	(*this->e)(oLeft + Renderer::_cSize/2,oTop,(char)25);

	// bottom middle
	(*this->e)(oLeft + Renderer::_cSize/2-1,oTop + Renderer::_cSize-1,(char)24);
	(*this->e)(oLeft + Renderer::_cSize/2,oTop + Renderer::_cSize-1,(char)24);

	
	// middle left
	(*this->e)(oLeft,oTop + Renderer::_cSize/2 - 1,(char)45);
	(*this->e)(oLeft,oTop + Renderer::_cSize/2,(char)45);

	// middle right
	(*this->e)(oLeft + Renderer::_cSize - 1,oTop + Renderer::_cSize/2 - 1,(char)45);
	(*this->e)(oLeft + Renderer::_cSize - 1,oTop + Renderer::_cSize/2,(char)45);
}

void Renderer::drawFigures() {
	for(int c = 0; c < Renderer::_bSize; ++c)
		for(int r = 0; r < Renderer::_bSize; ++r)
			if( this->b->at(c,r) )
				this->drawFigure(this->b->at(c,r),this->b->cellAt(c,r));
}

void Renderer::drawFigure(const Figure *fig,const Cell *cell) {
	
	int tColor = fig->isBlack() ? (int)_BLACK : (int)_WHITE;
	int tFig = -1;
	if( dynamic_cast<const Pawn *>(fig) )
		tFig = (int)_PAWN;
	if( dynamic_cast<const Rook *>(fig) && !dynamic_cast<const Queen *>(fig) )
		tFig = (int)_ROOK;
	if( dynamic_cast<const Bishop *>(fig) && !dynamic_cast<const Queen *>(fig) )
		tFig = (int)_BISHOP;
	if( dynamic_cast<const Knight *>(fig) )
		tFig = (int)_KNIGHT;
	if( dynamic_cast<const Queen *>(fig) )
		tFig = (int)_QUEEN;
	if( dynamic_cast<const King *>(fig) )
		tFig = (int)_KING;

	if ( tFig == -1 )
		return;
	for(int c = 0; c < Renderer::_cSize-2; ++c) {
		for(int r = 0; r < Renderer::_cSize-2; ++r){
			if( Renderer::textures[tFig][tColor][r][c] != ' ')
				(*this->e)(
					cell->col() * Renderer::_cSize + c + 1, 	
					( Renderer::_bSize - 1 - cell->row()) * Renderer::_cSize + r + 1,
					Renderer::textures[tFig][tColor][r][c]
				);
		}
	}
}

void Renderer::drawSelector() {
	if( this->selector.col < 0 || this->selector.col > Renderer::_bSize || 
		this->selector.row < 0 || this->selector.row > Renderer::_bSize )
	return;

	for(int c = 0; c < Renderer::_cSize; ++c) {
		for(int r = 0; r < Renderer::_cSize; ++r) {
			if( r == 0 || r == Renderer::_cSize - 1 || c == 0 || c == Renderer::_cSize - 1)
				(*this->e)(this->selector.col * Renderer::_cSize + c, this->selector.row * Renderer::_cSize + r,(char)249);
		}
	}
}

void Renderer::moveTarget(bool mv) {
	if( !mv ) return;
	int fCol = this->target.col;
	int fRow = Renderer::_bSize - this->target.row - 1;

	int tCol = this->selector.col;
	int tRow = Renderer::_bSize - this->selector.row - 1;

	if( this->b->at(fCol,fRow) ) {
		this->b->move(this->target.col,Renderer::_bSize - this->target.row - 1,this->selector.col,Renderer::_bSize - this->selector.row - 1);
	}
	this->target.col = this->selector.col;
	this->target.row = this->selector.row; 
	
}

void Renderer::moveSelector(Direction dir) {
	if( dir == UP )
		this->selector.row = this->selector.row - 1 < 0 ? Renderer::_bSize - 1 : this->selector.row - 1;

	if( dir == LEFT )
		this->selector.col = this->selector.col - 1 < 0 ? Renderer::_bSize - 1  : this->selector.col - 1;

	if( dir == DOWN )
		this->selector.row = this->selector.row + 1 >= Renderer::_bSize ? 0 : this->selector.row + 1;

	if( dir == RIGHT ) 
		this->selector.col = this->selector.col + 1 >= Renderer::_bSize ? 0 : this->selector.col + 1;
}

void Renderer::drawBoard() {
	for(int c = 0; c < Renderer::_bSize; ++c)
		for(int r = 0; r < Renderer::_bSize; ++r)
			this->drawCell(this->b->cellAt(c,r));
}

void Renderer::drawCell(const Cell *cell) {
	for(int c = 0; c < Renderer::_cSize; ++c)
		for(int r = 0; r < Renderer::_cSize; ++r)
			(*this->e)(Renderer::_cSize * cell->col() + c, ( Renderer::_bSize - 1 - cell->row()) * Renderer::_cSize + r , cell->isBlack() ?  Renderer::_bCell : Renderer::_wCell);
}
