#include "game.h"
#include "field.h"
#include <time.h>

// Konstruktoren
Game::Game(const size_t HEIGHT, const size_t WIDTH)
	: field(HEIGHT, WIDTH),
	actualBrick(nullptr),
	isGameOver(false)
{
	srand(static_cast<size_t>(time(NULL)));
}

// Methoden
bool Game::initializeNewBrick()
{
	if (this->actualBrick != nullptr)
		delete this->actualBrick;

	this->field.setCursor(0, (this->field.getWidth() / 2) - 1);

	this->actualBrick = getRandomBrick();

	return true;
}

void Game::print()
{
	if (this->actualBrick != nullptr)
	{
		if (this->field.isFree(this->actualBrick))
			this->field.drawBrick(this->actualBrick);
	}

	this->field.print();
}

Tetromino* Game::getRandomBrick()
{
	return new Tetromino(static_cast<Tetromino::TETROMINO>(rand() % 7));
}