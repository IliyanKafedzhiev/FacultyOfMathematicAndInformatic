#pragma once
#include "Board.h"
#include "Figure.h"
class Rook :
	public virtual Figure
{
public:
	Rook(ChessColor);
	virtual bool isValid(const Cell *,const Cell *,const Board *) const;
}; 

