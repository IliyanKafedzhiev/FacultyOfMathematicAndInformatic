#pragma once
#include "Rook.h"
#include "Bishop.h"

class Queen:
	public Rook,
	public Bishop
{
public:

	Queen(ChessColor);
	virtual bool isValid(const Cell *,const Cell *,const Board *) const;
}; 

