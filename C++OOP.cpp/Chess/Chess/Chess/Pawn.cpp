#include "Pawn.h"
#include <cmath>

Pawn::Pawn(ChessColor color): Figure(color) {

}

bool Pawn::isValid(const Cell *from,const Cell *to,const Board *board) const {
	if( !Figure::isValid(from,to,board) ) return false;

	int colDiff = (to->col() - from->col()) ;
	int rowDiff = (to->row() - from->row()) * (int)this->color;

	if( colDiff > 1 || colDiff < -1 || rowDiff > 2 ) // out of range or no move
		return false;

	if( rowDiff == 1 && !colDiff && !board->at(to->col(),to->row()) ) // simple forward move
		return true;
	
	if( rowDiff == 2 && 
		!this->getDidMove() &&
		( from->row() == 1 || from->row() == 6 ) && 
		!board->at(to->col(),to->row()) && 
		!board->at(to->col(),to->row() - (int)this->color) 
	) // initial 2 field move
		return true;

	const Figure *fig;
	if( colDiff && rowDiff == 1 && (fig = board->at(to->col(),to->row())) && fig->getColor() != this->color ) // normal take
		return true;

	Pawn *pwn;
	if( 
		rowDiff && colDiff && // move
		(fig = board->at(to->col(),to->row() - (int)this->color)) && // there is figure
		(pwn = dynamic_cast<Pawn*>((Figure*)fig)) && // it is also pawn
		pwn->getIsFirstMove() && // valid en passant target
		this->color != pwn->color // valid target
	) { // en passant
		return true;
	}

	return false;
}

