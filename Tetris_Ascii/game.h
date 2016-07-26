#ifndef GAME_H
#define GAME_H

#include "field.h"
#include "tetromino.h"

class Game
{
public:
	

	Game(size_t HEIGHT, size_t WIDHT);

	bool initializeNewBrick();
	void print() const;

private:

	Field field;

	Tetromino *actualBrick;

	bool isGameOver;

	Tetromino *getRandomBrick();
};






#endif // !GAME_H
