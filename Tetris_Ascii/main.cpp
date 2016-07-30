#include "functions.h"
#include "game.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	Game tetris(20, 10);
	//Tetromino ted(Tetromino::TETROMINO::I);
	tetris.initializeNewBrick();
	tetris.getField().drawBrick(tetris.getActualBrick());
	tetris.print();
	

	int key;

	Field &feld = tetris.getField();
	int i = 0;
	//int a,b;
	//string aa, bb;

	while (tetris.run())
	{
		if (_kbhit())
		{
			key = _getch();
			tetris.action(key);
			key = ' ';

			feld.clear(tetris.getActualBrick()->getFormat());
			feld.drawBrick(tetris.getActualBrick());
			clearScreen();
			tetris.print();
		}
	


		i++;
		if (i % 30000 == 0)
		{
			Field::Point alt(feld.getCursor().getX(), feld.getCursor().getY());
			feld.setCursor(feld.getCursor().getX() + 1, feld.getCursor().getY());
			

			if (feld.isFree(tetris.getActualBrick()))
			{	
				feld.clear(tetris.getActualBrick()->getFormat());
				feld.drawBrick(tetris.getActualBrick());
				i = 0;
				clearScreen();
				tetris.print();
			}
			else {
				feld.setCursor(feld.getCursor().getX() - 1, feld.getCursor().getY());
				feld.drawBrick(tetris.getActualBrick(), 'X');
				tetris.initializeNewBrick();
				clearScreen();
				tetris.print();
			}
		}
	}
		
	clearScreen();
	cout << "GAME OVER" << endl;
	system("PAUSE");
	return 0;
}