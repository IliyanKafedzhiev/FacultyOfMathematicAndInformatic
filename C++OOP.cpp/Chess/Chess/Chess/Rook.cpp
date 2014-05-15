#include "Rook.h"
#include <algorithm>

Rook::Rook(ChessColor color): Figure(color) {

}

bool Rook::isValid(const Cell *from,const Cell *to,const Board *board) const {

	if( !Figure::isValid(from,to,board) ) return false;

	if( from->col() - to->col() != 0 && from->row() - to->row() != 0 ) // move not in straight line
		return false;

	// check for figures in the way
	if ( from->col() - to->col() ) {
		// horizontal move
		int colMove = from->col() < to->col() ? 1 : -1;
		for(int c = from->col(); c*colMove < to->col()*colMove; c += colMove)
			if( board->at(c,from->row()) )
				return false;
	} else {
		// vertical move
		int rowMove = from->row() < to->row() ? 1 : -1;
		for(int r = from->row(); r * rowMove < to->row() * rowMove; r += rowMove)
			if( board->at(from->col(),r) )
				return false; 
	}
	return true;
}