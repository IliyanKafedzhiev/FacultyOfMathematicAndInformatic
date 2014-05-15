#pragma once
#include "Board.h"
#include "Figure.h"

class King :
	public Figure
{
public:
	King(ChessColor);
	virtual bool isValid(const Cell *,const Cell *,const Board *) const;
	bool isUnderAttack(const Cell *,const Board *) const;
};

