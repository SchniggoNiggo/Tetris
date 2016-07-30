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
	void print() const;
	void printNextBrick() const;
	bool run();
	void action(int key);
	void move(int key);
	Field& getField();
	Tetromino* getActualBrick() const;

private:
	// Eigenschaften
	Field field;
	Tetromino *actualBrick;
	Tetromino *nextBrick;
	bool isGameOver;

	// Methoden
	Tetromino* getRandomBrick();

};

#endif