#include "Bishop.h"
#include <algorithm>

Bishop::Bishop(ChessColor color): Figure(color) {

}

bool Bishop::isValid(const Cell *from,const Cell *to,const Board *board) const {

	if( !Figure::isValid(from,to,board) ) return false;

	if( abs(from->col() - to->col()) != abs(from->row() - to->row()) ) // not diagonal move
		return false;
	
	int rowChange = ( (from->row() - to->row() < 0) - (from->row() - to->row() > 0) ); // direction
	if ( from->col() - to->col() > 0 ) { // from is right of to
		for ( int c = from->col(), r = from->row(); c < to->col() ; --c, r += rowChange)
			if ( board->at(c,r) )
				return false;
	} else { // from is left of to
		for ( int c = to->col(), r = to->row(); c < from->col(); ++c, r += rowChange)
			if ( board->at(c,r) )
				return false;
	}

	return true;
}
