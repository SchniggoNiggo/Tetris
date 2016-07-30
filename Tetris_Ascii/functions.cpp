//Includes
#include "functions.h"
#include <Windows.h>
//Methoden
void clearScreen() {
	HANDLE hOut;
	COORD position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	position.X = 0;
	position.Y = 0;

	SetConsoleCursorPosition(hOut, position);
}