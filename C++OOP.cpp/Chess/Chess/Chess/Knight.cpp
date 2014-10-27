#include "Knight.h"
#include <cmath>

Knight::Knight(ChessColor color): Figure(color) {

}

bool Knight::isValid(const Cell *from,const Cell *to,const Board *board) const {
	if( !Figure::isValid(from,to,board) ) return false;


	if( std::abs( from->col() - to->col() ) == 2 && std::abs( from->row() - to->row() ) == 1 ||
		std::abs( from->col() - to->col() ) == 1 && std::abs( from->row() - to->row() ) == 2 
	)
		return true;

	return false;
}
