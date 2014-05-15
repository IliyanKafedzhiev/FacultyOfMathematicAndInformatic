#pragma once
#include "Engine.h"
#include "Board.h"
enum Direction : char { NONE, UP, DOWN, LEFT, RIGHT};
enum _tFigures : int { _PAWN = 0, _ROOK, _KNIGHT, _BISHOP, _QUEEN, _KING};
enum _tColors : int { _BLACK = 0, _WHITE };
class Renderer
{
public:
	Renderer(Engine *,Board *);
	void draw();
	void drawCell(const Cell *);
	void drawSelector();
	void drawTarget();
	void drawBoard();
	void drawFigures();
	void drawFigure(const Figure *,const Cell *);
	void moveSelector(Direction);
	void moveTarget(bool);
protected:
	struct {int col,row;} selector;
	struct {int col,row;} target;

	static const int _cSize = 10;
	static const int _bSize = 8;

	static const char _bCell = (char)176;
	static const char _wCell = (char)219;

	static const char textures[6][2][8][9];

	Board *b;
	Engine *e;
};

