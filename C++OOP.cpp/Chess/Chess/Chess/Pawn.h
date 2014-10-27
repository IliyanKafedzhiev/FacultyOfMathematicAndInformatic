#pragma once
#include "Board.h"
#include "Figure.h"
class Pawn:
	public Figure
{
public:
	Pawn(ChessColor);
	virtual bool isValid(const Cell *,const Cell *,const Board *) const;
};

