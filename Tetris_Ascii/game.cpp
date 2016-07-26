#include "game.h"
#include <time.h>
#include "field.h"


Game::Game(size_t HEIGHT, size_t WIDHT)
	: isGameOver(false), actualBrick(nullptr), field(HEIGHT, WIDHT)
{
	srand((size_t)time(NULL));
}

bool Game::initializeNewBrick()
{
	if (this->actualBrick != nullptr)
	{
		delete this->actualBrick;
	}
	this->field.setCursor(0, (this->field.getWidth()/2)-1);
	this->actualBrick = getRandomBrick();


	if (true)
	{
		
	}
	return false;
}

void Game::print()const  {

	if (this->actualBrick != nullptr)
	{
		this->actualBrick->print();
	}
	
	//this->field.print();
}



Tetromino* Game::getRandomBrick()
{
	return new Tetromino( (Tetromino::TETROMINO)(rand() % 7));
};