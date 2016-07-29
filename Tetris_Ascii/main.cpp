#include "functions.h"
#include "game.h"

#include <cstdlib>
#include <conio.h>

int main()
{
	Game tetris(20, 20);

	tetris.initializeNewBrick();
	tetris.getField().drawBrick(tetris.getActualBrick());
	tetris.print();
	

	int key;

	Field &feld = tetris.getField();
	int i = 0;
	while (true)
	{
		i++;
		if (i % 300000000 == 0)
		{			
			feld.setCursor(feld.getCursor().getX() + 1, feld.getCursor().getY());
			if (feld.isFree(tetris.getActualBrick()))
			{
				clearScreen();
				feld.clear(Field::Point(feld.getCursor().getX()-1, feld.getCursor().getY()), tetris.getActualBrick());
				feld.drawBrick(tetris.getActualBrick());
				tetris.print();
				i = 0;
			}
			else {
				feld.setCursor(feld.getCursor().getX() - 1, feld.getCursor().getY());
			}
		}
		
	}

	/*while( true )
	{
	clearScreen();
	ted.print();
	if( _kbhit() )
	{
	key = _getch();

	switch( key )
	{
	case 'a':
	case 'A':
	ted.rotate( 'a' );
	break;
	case 'd':
	case 'D':
	ted.rotate( 'd' );
	break;
	}

	key = ' ';
	}
	}*/

	system("PAUSE");
	return 0;
}