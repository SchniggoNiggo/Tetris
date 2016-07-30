#include "game.h"
#include "field.h"
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;
// Konstruktoren
Game::Game(const size_t HEIGHT, const size_t WIDTH)
	: field(HEIGHT, WIDTH),
	actualBrick(nullptr),
	isGameOver(false),
	nextBrick(nullptr),
	intervall(1000),
	highscore(0)
{
	srand(static_cast<size_t>(time(NULL)));
}

// Methoden
bool Game::initializeNewBrick()
{
	if (this->actualBrick != nullptr)
		delete this->actualBrick;

	this->field.setCursor(0, (this->field.getWidth() / 2) - 1);

	if (this->nextBrick != nullptr)
	{
		this->actualBrick = this->nextBrick;
		this->nextBrick = getRandomBrick();
	}
	else
	{
		this->actualBrick = getRandomBrick();
	}
	this->nextBrick = getRandomBrick();
	

	if (this->field.isFree(this->actualBrick))
	{
		return true;
	}
	else
	{	
		this->isGameOver = true;
		return false;
	}
}

void Game::print() const
{
	this->field.print();
}

void Game::printNextBrick() const
{
	if (this->nextBrick!=nullptr)
	{
		this->nextBrick->print();
	}
}

bool Game::run()
{
	return !this->isGameOver;
}

void Game::action(int key)
{
	switch (key)
	{
	case 224:
		this->move(key);
		break;
	case 'A':
	case 'a':
		this->actualBrick->rotate('a');
		if (!this->field.isFree(this->getActualBrick()))
		{
			this->actualBrick->rotate('d');
		}
		break;
	case 'D':
	case 'd':
		this->actualBrick->rotate('d');
		if (!this->field.isFree(this->getActualBrick()))
		{
			this->actualBrick->rotate('a');
		}
		break;

	case ' ':
		int i;
		system("CLS");
		//PlaySound(TEXT("SystemStart"), nullptr, SND_ALIAS|SND_ASYNC);
		PlaySound(nullptr, 0, 0);
		cout << "Das Spiel ist pausiert, drücke eine beliebige zum fortfahren..." << endl;
		system("PAUSE");
		PlaySound("tetrisMusic", nullptr, SND_RESOURCE | SND_ASYNC);
		system("CLS");
		break;
	}
}

void Game::move(int key)
{
	key = _getch();
	switch (key)
	{
	case 75: //left
		this->field.setCursor(this->field.getCursor().getX(), this->field.getCursor().getY() -1 );
		if (!this->field.isFree(this->getActualBrick()))
		{
			this->field.setCursor(this->field.getCursor().getX(), this->field.getCursor().getY() + 1);
		}
		break;
	case 77: //right
		this->field.setCursor(this->field.getCursor().getX(), this->field.getCursor().getY() + 1);
		if (!this->field.isFree(this->getActualBrick()))
		{
			this->field.setCursor(this->field.getCursor().getX(), this->field.getCursor().getY() - 1);
		}
		break;
	case 80: //down
		this->field.setCursor(this->field.getCursor().getX() + 1, this->field.getCursor().getY());
		if (!this->field.isFree(this->getActualBrick()))
		{
			this->field.setCursor(this->field.getCursor().getX() - 1, this->field.getCursor().getY());
		}
		break;
	}
}

//void Game::tempActualBrick(const Tetromino * brick)
//{
//	this->field.tamp(brick);
//}

Field & Game::getField()
{
	return this->field;
}

Tetromino * Game::getActualBrick() const
{
	return this->actualBrick;
}

const size_t & Game::getIntervall() const
{
	return this->intervall;
}

const size_t & Game::getHighscore() const
{
	return this->highscore;
}

int Game::updateHighscore(const size_t & lines)
{
	int level = 1;
	switch (lines)
	{
	case 1: this->highscore += 2000;
		break;
	case 2:	this->highscore += 2500;
		break;
	case 3:	this->highscore += 3000;
		break;
	case 4:	this->highscore += 5000;
		break;
	}


	if (this->highscore <= 15000)
	{
		level = 1;
		this->intervall = 1000;
	}
	if (this->highscore > 15000 && highscore < 25000)
	{
		level = 2;
		this->intervall = 900;
	}
	if (this->highscore > 25000 && highscore < 30000)
	{
		level = 3;
		this->intervall = 800;
	}
	if (this->highscore > 30000 && highscore < 35000)
	{
		level = 4;
		this->intervall = 700;
	}
	if (this->highscore > 35000 && highscore < 40000)
	{
		level = 5;
		this->intervall = 600;
	}
	if (this->highscore > 40000 && highscore < 45000)
	{
		level = 6;
		this->intervall = 500;
	}
	if (this->highscore > 45000 && highscore < 50000)
	{
		level = 7;
		this->intervall = 450;
	}
	if (this->highscore > 50000 && highscore < 55000)
	{
		level = 8;
		this->intervall = 400;
	}
	if (this->highscore > 55000 && highscore < 60000)
	{
		level = 9;
		this->intervall = 300;
	}
	if (this->highscore > 60000)
	{
		level = 10;
		this->intervall = 150;
	}
	return level;
}

Tetromino* Game::getRandomBrick()
{
	return new Tetromino(static_cast<Tetromino::TETROMINO>(rand() % 7));
}