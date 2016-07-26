#include <iostream>
using namespace std;

//#include "field.h"
//#include "tetromino.h"
#include <conio.h>
#include <Windows.h>
#include "functions.h"
#include "game.h"


int main() {
	Tetromino ted(Tetromino::S);
	Game tetris(20, 20);
	
	/*tetris.initializeNewBrick();
	tetris.print();*/

		tetris.initializeNewBrick();
		tetris.print();

	int key;

	/*while (true)
	{
		clearScreen();
		ted.print();
		if (_kbhit())
		{
			key = _getch();

			switch (key)
			{
			case 'a':
			case 'A':
				ted.rotate('a');
				break;
			case 'd':
			case 'D':
				ted.rotate('d');
				break;
			}

			key = ' ';
		}

		

	}*/

	system("PAUSE");
	return 0;
}