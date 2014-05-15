#include "Figure.h"
#include "Board.h"

Figure::Figure(ChessColor color) {
	this->color = color;
	this->moves = 0;
}

bool Figure::isWhite() const {
	return this->color == WHITE;
}

bool Figure::isBlack() const {
	return !this->isWhite();
}

ChessColor Figure::getColor() const {
	return this->color;
}

bool Figure::isValid(const Cell *from,const Cell *to,const Board *board) const {
	const Figure *fig;
	return (from->col() != to->col() || from->row() != to->row()) && // move at all
		( !board->at(to->col(),to->row()) ||  (fig = board->at(to->col(),to->row())) && this->color != fig->color ); // no fig at 'to' or opposite color
}

bool Figure::getIsFirstMove() const {
	return this->moves == 1;
}

bool Figure::getDidMove() const {
	return this->moves;
}

void Figure::doMove() {
	this->moves++;
}
