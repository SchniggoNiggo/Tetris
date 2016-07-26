#ifndef GAME_H
#define GAME_H

#include "field.h"
#include "tetromino.h"

class Game
{
public:
	

	Game(size_t HEIGHT, size_t WIDHT);

	void print() const;

private:



	Field field;

	Tetromino *actualBrick;

	bool isGameOver;


};






#endif // !GAME_H
