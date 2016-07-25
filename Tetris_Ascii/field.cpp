#include "field.h"
#include <iostream>
using std::cout;
using std::endl;

Field::Field(size_t HEIGHT, size_t WIDHT)
	: field(nullptr), HEIGHT(HEIGHT), WIDHT(WIDHT)
{
	this->field = new char*[HEIGHT];

	for (size_t i = 0; i < HEIGHT; i++)
	{
		this->field[i] = new char[WIDHT];

		for (size_t j = 0; j < WIDHT; j++)
		{
			this->field[i][j] = ' ';
		}
	}

	for (size_t i = 0; i < HEIGHT - 1; i++)
	{
		this->field[i][0] = '|';
		this->field[i][WIDHT - 1] = '|';
	}

	for (size_t i = 0; i < WIDHT; i++)
	{
		this->field[HEIGHT - 1][i] = '-';
	}
}

void Field::print() const {
	for (size_t i = 0; i < this->HEIGHT; i++)
	{
		for (size_t j = 0; j < this->WIDHT; j++)
		{
			cout << this->field[i][j];
		}
		cout << endl;
	}

}

Field::~Field() {
	for (size_t i = 0; i < HEIGHT; i++)
	{
		delete[] this->field[i];
	}
	delete[] this->field;
}