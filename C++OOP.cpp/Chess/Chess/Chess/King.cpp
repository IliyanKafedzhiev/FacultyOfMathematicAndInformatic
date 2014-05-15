#include "King.h"
#include "Rook.h"
#include <cmath>
#include <algorithm>

King::King(ChessColor color): Figure(color) {

}

bool King::isValid(const Cell *from,const Cell *to,const Board *board) const {
	if( !Figure::isValid(from,to,board) ) return false;


	const Figure *fig;
	Rook *rook;
	if( 
		from->row() == to->row() && // same row
		abs(from->col() - to->col()) == 2 && // castle move
		!this->getDidMove() && // king didnt move
		(fig = board->at( from->col() > to->col() ? 0 : 7 ,from->row() )) && // there is figure
		(rook = dynamic_cast<Rook*>((Figure*)fig)) && // and it is rook
		!rook->getDidMove() // and it didnt move either
	){ // castle attempt
		for(int c = std::min(from->col(),to->col()); c < std::max(from->col(),to->col()); ++c)
			if( board->at(c,to->row()) || board->fieldUnderAttack(board->cellAt(c,to->row()),(ChessColor)((int)this->color * -1)) )
				return false;
		return true;
	}

	if( std::abs( from->col() - to->col() ) > 1 || std::abs( from->row() - to->row() ) > 1)
		return false;

	if( this->isUnderAttack(to,board) )
		return false;
	
	return true;
}

bool King::isUnderAttack(const Cell *pos,const Board *board) const {
	return board->fieldUnderAttack(pos,(ChessColor)((int)this->color * -1));
}