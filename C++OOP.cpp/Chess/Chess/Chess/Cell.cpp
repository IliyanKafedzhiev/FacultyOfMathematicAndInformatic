#include "Cell.h"

Cell::Cell(const char *pos): _row(0), _col(0) {
	this->_setCol(Cell::toIndex(*pos));
	this->_setRow(Cell::toIndex(*(pos+1)));
}

Cell::Cell(char c,char r): _row(0), _col(0) {
	this->_setCol(Cell::toIndex(c));
	this->_setRow(Cell::toIndex(r));
}

Cell::Cell(char c,int r): _row(0), _col(0) {
	this->_setCol(Cell::toIndex(c));
	this->_setRow(r);
}

Cell::Cell(int c,int r): _row(0), _col(0) {
	this->_setCol(c);
	this->_setRow(r);
}

int Cell::row() const {
	return this->_row;
}

int Cell::col() const {
	return this->_col;
}

int Cell::toIndex(char c) {
	return c > '0' && c <= '8' ? c - '1' : Cell::isValid(c) ? (c-1) % 8 : -1;
}

bool Cell::isValid(char c) {
	return c >= 'a' && c <= 'h' || c >= 'A' && c <= 'H';
}

void Cell::_setCol(int col) {
	this->_col = col != -1 ? col : this->_col;
}

void Cell::_setRow(int row) {
	this->_row = row != -1 ? row : this->_row;
}

bool Cell::isWhite() const {
	return (!(this->_row % 2) && (this->_col % 2)) || ( (this->_row % 2) && !(this->_col % 2) ); 
}

bool Cell::isBlack() const {
	return !this->isWhite();
}