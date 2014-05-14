#include <iostream>
#include "Board.h"
#include "Figure.h"
#include "Engine.h"
#include "Renderer.h"
#include <Windows.h>

using namespace std;

Direction readSelectorMove();
bool readTargetMove();

int main() {
	Board board;

	
	Engine engine(80,80,true);
	Renderer renderer(&engine,&board);

	while(true) {
		if( GetAsyncKeyState(VK_SPACE) ) {
			for(int c = 0; c < 256; ++c){
				cout << c << " [" << (char)c << "]    ";
				if( c % 5 == 0 ) cout << "      " << endl;
			}
			cin.get();
		}


		renderer.draw();
		renderer.moveSelector(readSelectorMove());
		renderer.moveTarget(readTargetMove());
		engine.draw();
		Sleep(1000/60);
	}


	cin.get();
	return 0;
}

bool readTargetMove() {
	return (bool)GetAsyncKeyState(VK_RETURN);
}

Direction readSelectorMove() {
	static int lastRead = GetTickCount();
	if( GetTickCount() - lastRead < 200 )
		return NONE;
	lastRead = GetTickCount();
	return GetAsyncKeyState(VK_LEFT) ? LEFT : GetAsyncKeyState(VK_RIGHT) ? RIGHT : GetAsyncKeyState(VK_UP) ? UP : GetAsyncKeyState(VK_DOWN) ? DOWN : NONE;
}