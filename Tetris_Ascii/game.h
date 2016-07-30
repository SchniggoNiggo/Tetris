//Definition Header
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

	//Getter
	Field& getField();
	Tetromino* getActualBrick() const;
	const size_t& getIntervall() const;
	const size_t& getHighscore() const;

	//Setter
	int updateHighscore(const size_t &lines);

private:

	// Eigenschaften
	Field field;
	Tetromino *actualBrick;
	Tetromino *nextBrick;
	bool isGameOver;
	unsigned short intervall;
	size_t highscore;

	// Methoden
	Tetromino* getRandomBrick();
	

};

#endif