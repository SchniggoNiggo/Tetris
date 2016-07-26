#include "functions.h"
#include "game.h"

#include <cstdlib>
#include <conio.h>

int main()
{
	Tetromino ted(Tetromino::J);
	Game tetris(15, 10);

	tetris.initializeNewBrick();
	tetris.print();

	int key;

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