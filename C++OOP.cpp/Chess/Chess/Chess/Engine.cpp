#include "Engine.h"
#pragma warning(disable: 4996)

Engine::Engine(int cols,int rows,bool debug): debug(debug), field(NULL), nextFrame(NULL) {
	this->pixelSize.x = 5;
	this->pixelSize.y = 5;
	this->console = GetStdHandle(STD_OUTPUT_HANDLE);
	this->field = new char*[rows];
	this->nextFrame = new char*[rows];
	for (int c = 0; c < rows; ++c)	{
		this->field[c] = new char[cols];
		this->nextFrame[c] = new char[cols];
		for (int r = 0; r < cols; ++r) 
			this->nextFrame[c][r] = this->field[c][r] = ' ';
	}
	this->_setFontSize(this->pixelSize.x,this->pixelSize.y);
	this->rows = rows;
	this->cols = cols;
	this->drawBuff = new char[this->cols*this->rows + this->cols + 1];
	this->lastCol = this->lastRow = 0;
	RECT desktop;
	GetWindowRect(GetDesktopWindow(), &desktop);
	this->_moveConsole(desktop.right/2 - cols*this->pixelSize.x/2,20);
	this->_hideBrush();
	this->_resizeConsole(rows,cols);
	this->pixelsDrawn = this->drawTime = 0;
}

void Engine::draw(DrawMethod d) {
	this->drawTime = GetTickCount();
	this->pixelsDrawn = 0;
	if( d == Clean ){
		int c = 0;
		for (int row = 0; row < this->rows; ++row) {
			for (int col = 0; col < this->cols; ++col)
				this->field[row][col] = this->drawBuff[c++] = this->nextFrame[row][col];
			this->drawBuff[c++] = '\n';
		}
		this->drawBuff[c-1] = 0;
		this->pixelsDrawn = c;
		this->_moveBrush(0,0);
		printf(this->drawBuff);
	} else {
		// TODO: optimise to draw larger blocks than 1 line
		for (int row = 0; row < this->rows; ++row)	{
			bool endLine = false;
			for (int col = 0; col < this->cols; ++col)	{
				if( this->field[row][col] != this->nextFrame[row][col] ){
					int len = 0;
					bool brushMoved = false;
					while( this->field[row][col] != this->nextFrame[row][col] && col < this->cols ){
						if( !brushMoved ){
							this->_moveBrush(row,col);
							brushMoved = true;
						}
						this->drawBuff[len++] = this->field[row][col] = this->nextFrame[row][col];
						++col;
						this->pixelsDrawn++;
					}
					if( len != 0 ) {
						this->drawBuff[len] = 0;
						printf(this->drawBuff);
					}
				}
			}
		}
	}
	this->drawTime = GetTickCount() - this->drawTime;
	if( this->debug ) {
		if( this->drawTime ) {
			this->_moveBrush(this->rows,0);
			printf("Last draw time: %d    ",this->drawTime);
			
		}
		if( this->pixelsDrawn ) {
			this->_moveBrush(this->rows+1,0);
			printf("Last drawn pixels: %d   ",this->pixelsDrawn);
		}
		
		
	}
}

int Engine::getWidth() const {
	return this->cols;
}

int Engine::getHeight() const {
	return this->rows;
}

int Engine::getPixelsDrawn() const {
	return this->pixelsDrawn;
}

// not used
void Engine::_getNextBlock(int row,int col,char * buf){
	int counter = 0;
	while( this->nextFrame[row][col] != this->field[row][col] ){
		this->field[row][col] = this->nextFrame[row][col];
		buf[counter++] = this->nextFrame[row][col];
		if( col == this->cols -1 ){
			row++;
			col = 0;
		} else if( col < this->cols - 1 && row < this->rows - 1 ){
			col++;
		} else {
			break;
		}		
	}
}

void Engine::clear(){
	for (int row = 0; row < this->rows; ++row)
		for (int col = 0; col < this->cols; ++col)
			this->nextFrame[row][col] = ' ';
	this->lastCol = this->lastRow = 0;
}

void Engine::fill(RECT area,char fill) {
	if( !this->_inBounds(area) )
		return;
	for (int row = area.top; row <= area.bottom; ++row)
		for (int col = area.left; col <= area.right; ++col) 
			this->nextFrame[row][col] = fill;

	this->lastCol = area.right;
	this->lastRow = area.bottom;
}

void Engine::drawLineH(int col,int row,int len,char fill) {
	char str[2] = {fill,0};
	this->drawLineH(col,row,len,str);
}

void Engine::drawLineH(int col,int row,int len,const char *str) {
	RECT area = {col,row,col+len-1,row};
	if( !this->_inBounds(area) )
		return;
	int strLen = strlen(str),index = 0;
	for(int c = col; c < col + len; ++c){
		this->nextFrame[row][c] = str[index];
		index = index + 1 == strLen ? 0 : index + 1;
	}
	this->lastRow = row;
	this->lastCol = col + len;
}

void Engine::drawLineV(int col,int row,int len,char fill){
	char str[2] = {fill,0};
	this->drawLineV(col,row,len,str);
}

void Engine::drawLineV(int col,int row,int len,const char *str) {
	RECT area = {col,row,col,row+len-1};
	if( !this->_inBounds(area) )
		return;
	int strLen = strlen(str),index = 0;
	for(int r = row; r < row + len; ++r){
		this->nextFrame[r][col] = str[index];
		index = index + 1 == strLen ? 0 : index + 1;
	}
	this->lastRow = row + len;
	this->lastCol = col;
}
void Engine::operator()(int col,int row,char c){
	RECT check = {col,row,col,row};
	if( !this->_inBounds(check) ) return;
	this->nextFrame[row][col] = c;
	this->lastCol = col;
	this->lastRow = row;
}

void Engine::operator()(int col,int row,const char *str){
	this->operator()(col,row,str,strlen(str));
}

void Engine::operator()(int col,int row,const char *str,int len){
	int c = 0;
	for( ; c < len && (col + c) < this->cols; c++)
		this->nextFrame[row][col+c] = str[c];
	
	this->lastRow = row;
	this->lastCol = col + c;
}

void Engine::operator()(int x){
	char str[40];
	this->operator()(this->lastCol,this->lastRow,str,sprintf_s(str, 40,"%d",x));
}

void Engine::operator()(char c){
	this->nextFrame[this->lastRow][this->lastCol++] = c;
}

void Engine::operator()(const char *str){
	this->operator()(this->lastCol,this->lastRow,str,strlen(str));
}

void Engine::operator()(const char *str,int len){
	this->operator()(this->lastCol,this->lastRow,str,len);
}

bool Engine::_inBounds(RECT area) const {
	return area.top >= 0 && area.top < this->rows && 
		   area.bottom >= 0 && area.bottom < this->rows &&
		   area.left >= 0 && area.left < this->cols && 
		   area.right >= 0 && area.right < this->cols;
}

void Engine::_moveConsole(int x,int y) const{
	MoveWindow(GetConsoleWindow(),x,y,this->cols,this->rows,true);
}

void Engine::_hideBrush() const {
	CONSOLE_CURSOR_INFO cur;
	cur.dwSize = 1;
	cur.bVisible = false;  
	SetConsoleCursorInfo(this->console, &cur);
}

void Engine::_endLine(int row){
	COORD position = {row,this->cols};
	SetConsoleCursorPosition(this->console, position);
	printf("\n");
}

void Engine::_moveBrush(int row,int col) {
	static COORD position;
	position.X = col;
	position.Y = row;
	SetConsoleCursorPosition(this->console, position);
}

void Engine::_setFontSize(int x,int y) const{
	RECT desktop;
	GetWindowRect(GetDesktopWindow(), &desktop);
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	HWND hwConsole = GetConsoleWindow();
	RECT cons;
	
	PCONSOLE_FONT_INFOEX pFont = new CONSOLE_FONT_INFOEX() ;
	pFont->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(hConsole,0,pFont);

	int diff = 100,bX,bY;

	for(int c = 25; c >= x; --c) {
		for(int r = 25; r >= y; --r) {
			
			pFont->dwFontSize.X = c;
			pFont->dwFontSize.Y = r;
			SetCurrentConsoleFontEx(hConsole,0,pFont);
			GetCurrentConsoleFontEx(hConsole,0,pFont);
			GetWindowRect(hwConsole, &cons);

			if( pFont->dwFontSize.X == c && pFont->dwFontSize.Y == r && cons.bottom - cons.top < desktop.bottom && abs(c-r) < diff ) {
				bX = c;
				bY = r;
				diff = abs(c-r);
			} 
		}
	}

	pFont->dwFontSize.X = bX;
	pFont->dwFontSize.Y = bY;
	SetCurrentConsoleFontEx(hConsole,0,pFont);
	delete pFont;
}

void Engine::_resizeConsole(int rows,int cols) const{

	++cols;
	if( this->debug ) rows += 2;
	
	char *buf = new char[50];
	sprintf_s(buf,50,"mode %d, %d",cols,rows);
	system(buf);
	delete[] buf;

	SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = rows+1;
	Rect.Right = cols+1;
	SetConsoleWindowInfo(this->console, TRUE, &Rect);


}


Engine::~Engine() {
	if( this->field ){
		for (int c = 0; c < rows; ++c)
			if( this->field[c] )
				delete[] this->field[c];
		delete[] this->field;
	}

	if( this->nextFrame ) {
		for (int c = 0; c < rows; ++c)
			if( this->nextFrame[c] )
				delete[] this->nextFrame[c];
		delete[] this->nextFrame;
	}
}
