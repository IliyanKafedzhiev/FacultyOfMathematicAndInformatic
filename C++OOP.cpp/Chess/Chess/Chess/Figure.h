#pragma once
#include "Cell.h"
enum ChessColor { WHITE = 1, BLACK = -1 };
class Board;

class Figure
{
public:
	Figure(ChessColor);
	virtual bool isValid(const Cell *,const Cell *,const Board *) const;
	bool isWhite() const;
	bool isBlack() const;
	ChessColor getColor() const;

	bool getDidMove() const;
	bool getIsFirstMove() const;
	void doMove();
protected:
	ChessColor color;
	int moves;
	
};

