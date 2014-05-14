#pragma once
#include "Board.h"
#include "Figure.h"
class Bishop :
	public virtual Figure
{
public:
	Bishop(ChessColor);
	virtual bool isValid(const Cell *,const Cell *,const Board *) const;
}; 

