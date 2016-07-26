#include "game.h"


Game::Game(size_t HEIGHT, size_t WIDHT)
	: isGameOver(false), actualBrick(nullptr), field(HEIGHT, WIDHT)
{

}

void Game::print()const  {
	this->field.print();
};