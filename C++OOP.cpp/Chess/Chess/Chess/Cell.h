#pragma once
class Cell
{
public:
	Cell();
	Cell(const char *);
	Cell(char,char);
	Cell(char,int);
	Cell(int,int);

	static int toIndex(char);
	static bool isValid(char);

	int col() const;
	int row() const;

	bool isWhite() const;
	bool isBlack() const;
protected:
	void _setCol(int);
	void _setRow(int);

	int _col;
	int _row;
}; 

