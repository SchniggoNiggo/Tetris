#ifndef TETROMINO_H
#define TETROMINO_H
#include <iostream>
#include <vector>

class Tetromino {
public:
	enum TETROMINO{ I, J, L, O, S, T, Z };
	
	Tetromino(TETROMINO type, char format = 'O', char whitespace = ' ');

	void print() const;
	void printAllTemplates() const;

	void rotate(int key);
	~Tetromino();

private:
	//Eigenschaften
	const char format;
	const char whitespace;
	TETROMINO type;
	char **actualBrickTemplate;
	size_t actualBrickIndex;
	std::vector<char**> brickFormTemplate;
	
	//Methoden
	void generateTemplate(const char t[4][4]);

};

#endif 
