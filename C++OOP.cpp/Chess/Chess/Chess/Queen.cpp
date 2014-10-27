#include "Queen.h"


Queen::Queen(ChessColor color): Rook(color), Bishop(color), Figure(color) {

} 

bool Queen::isValid(const Cell *from,const Cell *to,const Board *board) const {
	if( !Bishop::isValid(from,to,board) && !Rook::isValid(from,to,board) ) // not diagonal and not line move
		return false;
	return true;
}