#pragma once
#include <Windows.h>
#include <cstdio>

enum DrawMethod : char {Brush,Clean};
class Engine
{
public:
	Engine(int,int,bool debug = false);
	void operator()(int);
	void operator()(char);
	void operator()(const char *);
	void operator()(const char *,int);
	void operator()(int,int,char);
	void operator()(int,int,const char*);
	void operator()(int,int,const char*,int);
	void drawLineH(int,int,int,char);
	void drawLineH(int,int,int,const char *);
	void drawLineV(int,int,int,char);
	void drawLineV(int,int,int,const char *);
	void fill(RECT,char);

	void draw(DrawMethod d = Brush);
	void clear();
	int getPixelsDrawn() const;
	int getDrawTime() const;
	int getWidth() const;
	int getHeight() const;
	~Engine();
protected:
	HANDLE console;
	bool debug;
	int pixelsDrawn;
	int drawTime;
	int rows;
	int cols;
	int lastCol;
	int lastRow;
	struct {char x,y;} pixelSize;
	char **nextFrame;
	char **field;
	char *drawBuff;
	void _moveBrush(int,int);
	void _endLine(int);
	void _resizeConsole(int,int) const;
	void _getNextBlock(int,int,char *);
	void _moveConsole(int,int) const;
	void _hideBrush() const;
	void _setFontSize(int x = 1,int y = 1) const;
	void _line(RECT,const char*);
	bool _inBounds(RECT) const;
private:
	void operator=(const Engine &);
	Engine(const Engine &);
};

