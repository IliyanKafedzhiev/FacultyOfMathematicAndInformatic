#pragma once
#include "Board.h"
#include "Figure.h"

class Knight :
	public virtual Figure
{
public:
	Knight(ChessColor);
	virtual bool isValid(const Cell *,const Cell *,const Board *) const;
};

