#ifndef GAME_H
#define GAME_H

#include "field.h"

class Game
{
public:
	// Konstruktoren
	Game(const size_t HEIGHT, const size_t WIDTH);

	// Methoden
	bool initializeNewBrick();
	void print();

	Field& getField();
	const Tetromino* getActualBrick() const;

private:
	// Eigenschaften
	Field field;
	Tetromino *actualBrick;
	bool isGameOver;

	// Methoden
	Tetromino* getRandomBrick();
};

#endif