#include "game.h"
#include "field.h"
#include <time.h>
#include <conio.h>
#include <iostream>
using namespace std;
// Konstruktoren
Game::Game(const size_t HEIGHT, const size_t WIDTH)
	: field(HEIGHT, WIDTH),
	actualBrick(nullptr),
	isGameOver(false),
	nextBrick(nullptr)
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
		cout << "Das Spiel ist pausiert, drücke eine beliebige zum fortfahren..." << endl;
		system("PAUSE");
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

Tetromino* Game::getRandomBrick()
{
	return new Tetromino(static_cast<Tetromino::TETROMINO>(rand() % 7));
}