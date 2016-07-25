#include <iostream>
using namespace std;

#include "field.h"
#include "tetromino.h"
#include <conio.h>

int main() {
	
	


	//Tetromino i(Tetromino::I, 'O',' ');
	//i.printAllTemplates();
	//Tetromino j(Tetromino::J, 'O', ' ');
	//j.printAllTemplates();
	//Tetromino o(Tetromino::O, 'O', ' ');
	//o.printAllTemplates();
	//Tetromino s(Tetromino::S, 'O', ' ');
	//s.printAllTemplates();
	//Tetromino z(Tetromino::Z, 'O', ' ');
	//z.printAllTemplates();
	//Tetromino l(Tetromino::L, 'O', ' ');
	//l.printAllTemplates();
	//Tetromino tetromino(Tetromino::T, 'O', ' ');
	//tetromino.printAllTemplates();

	Field field(20, 20);
	field.print();

	Tetromino ted(Tetromino::T);
	int key;

	while (true)
	{
		system ("cls");
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

		

	}

	system("PAUSE");
	return 0;
}