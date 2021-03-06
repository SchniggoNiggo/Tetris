//Includes
#include "functions.h"
#include "game.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <cmath>
//pragma Winmedia lib
#pragma comment(lib, "winmm.lib")
using namespace std;


int main()
{
	HINSTANCE hInst;
	hInst = GetModuleHandle(NULL);
	setlocale(LC_ALL, "");
	Game tetris(15, 15);
	
	PlaySound("tetrisMusic",hInst, SND_RESOURCE | SND_ASYNC | SND_LOOP);
	
	tetris.initializeNewBrick();
	tetris.getField().drawBrick(tetris.getActualBrick());
	tetris.print();
	

	int key;

	Field &feld = tetris.getField();
	size_t actualTime = GetTickCount();

	long actualPlayTime = static_cast<size_t>(time(nullptr));

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
	
		bool tamp = false;
		
		if (tamp || actualTime + tetris.getIntervall() < GetTickCount())
		{
			actualTime = GetTickCount();
			feld.setCursor(feld.getCursor().getX() + 1, feld.getCursor().getY());
			

			if (feld.isFree(tetris.getActualBrick()))
			{	
				tamp = false;
				feld.clear(tetris.getActualBrick()->getFormat());
				feld.drawBrick(tetris.getActualBrick());
				clearScreen();
				tetris.print();
			}
			else {
				tamp = true;
				feld.setCursor(feld.getCursor().getX() - 1, feld.getCursor().getY());
				feld.drawBrick(tetris.getActualBrick(), 'X');
				size_t lines = feld.clearCompleteLines();
				tetris.updateHighscore(lines);
				tetris.updateHighscore(5);
				tetris.initializeNewBrick();
				clearScreen();
				tetris.print();
			}
			cout << endl;
			cout << "N�chster Stein:";
			cout << endl;
			tetris.printNextBrick();

			cout << endl;
			cout << "Punkte:";
			cout << endl;
			cout << tetris.getHighscore() << endl;
			cout << endl;

			cout << "Level:";
			cout << endl;
			cout << tetris.updateHighscore(0) << endl;

			cout << endl;
			cout << "made by Nico Jeske";
		}

		
	}
		


	system("CLS");
	cout << "GAME OVER" << endl;
	cout << "Score: " << tetris.getHighscore() << endl;
	int playtimeBerechner = static_cast<size_t>(time(nullptr)) - actualPlayTime;
	if (playtimeBerechner > 60)
	{
		int minuten = round(playtimeBerechner/60);
		int sekunden = playtimeBerechner % 60;
		cout << "Spielzeit: "  << minuten << " Minuten und " << minuten * 60 << " Sekunden." << endl;
	
	}
	else
	{
		cout << "Spielzeit: " << playtimeBerechner << " Sekunden" << endl;
	}
	
	system("PAUSE");
	return 0;
}