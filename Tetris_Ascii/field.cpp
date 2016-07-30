#include "field.h"
#include "functions.h"
#include "game.h"
#include <iostream>
using std::endl;
using std::cout;

// Konstruktoren
Field::Field(const size_t HEIGHT, const size_t WIDTH)
	: HEIGHT(HEIGHT),
	WIDTH(WIDTH),
	field(nullptr)
{
	this->field = new char*[this->HEIGHT];

	for (size_t i = 0; i<this->HEIGHT; i++)
	{
		this->field[i] = new char[this->WIDTH];

		for (size_t j = 0; j<this->WIDTH; j++)
			this->field[i][j] = ' ';
	}

	for (size_t i = 0; i<this->HEIGHT - 1; i++)
	{
		this->field[i][0] = '|';
		this->field[i][this->WIDTH - 1] = '|';
	}

	for (size_t i = 0; i<this->WIDTH; i++)
		this->field[this->HEIGHT - 1][i] = '^';
}

// getter
size_t Field::getHeight() const
{
	return this->HEIGHT;
}

size_t Field::getWidth() const
{
	return this->WIDTH;
}

const Field::Point& Field::getCursor() const
{
	return this->cursor;
}

// Methoden
void Field::setCursor(const unsigned short x, const unsigned short y)
{
	this->cursor.setX(x);
	this->cursor.setY(y);
}

void Field::print() const
{
	for (size_t i = 0; i<this->HEIGHT; i++)
	{
		for (size_t j = 0; j<this->WIDTH; j++)
			cout << this->field[i][j];

		cout << endl;
	}
}

bool Field::isFree(const Tetromino *brick)
{
	const char **tmp = brick->getActualBrickTemplate();

	const size_t x = this->cursor.getX();
	const size_t y = this->cursor.getY();

	if (x < 0 || x >= this->HEIGHT || y < 0 || y >= this->WIDTH)
		return false;

	for (size_t i = 0; i<4; i++)
	{
		for (size_t j = 0; j<4; j++)
		{
			if (tmp[i][j] == brick->getFormat())
			{
				if (this->field[x + i][y + j] == 'X'
					|| this->field[x + i][y + j] == '|'
					|| this->field[x + i][y + j] == '^')
					return false;
			}
		}
	}
	return true;
}

bool Field::drawBrick(const Tetromino *brick, char format)
{
	const char **tmp = brick->getActualBrickTemplate();

	/*for (size_t i = 0; i<4; i++)
	{
		for (size_t j = 0; j<4; j++)
		{
			if (tmp[i][j] == brick->getFormat())
				this->field[this->cursor.getX() + i][this->cursor.getY() + j] = format;
		}
	}
	return true;*/

	if (format != ' ')
	{
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				if (tmp[i][j] == brick->getFormat())
				this->field[this->cursor.getX() + i][this->cursor.getY() + j] = format;
			}
		}
	}
	/*else
	{
		for (size_t i = 0; i < length; i++)
		{

		}
	}*/
	return true;

}

//void Field::clear(const Point cursor, const Tetromino * brick)
//{
//	const char **tmp = brick->getActualBrickTemplate();
//
//	for (size_t i = 0; i<4; i++)
//	{
//		for (size_t j = 0; j<4; j++)
//		{
//			if (tmp[i][j] == brick->getFormat())
//				this->field[cursor.getX() + i][cursor.getY() + j] = ' ';
//		}
//	}
//}

void Field::clear(char format)
{
	//const char **tmp = brick->getActualBrickTemplate();

	for (size_t i = 0; i<this->getHeight(); i++)
	{
		for (size_t j = 0; j<getWidth(); j++)
		{
			if (this->field[i][j] == format)
				this->field[i][j] = ' ';
		}
	}
}

//void Field::tamp(const Tetromino * brick)
//{
//	const char **tmp = brick->getActualBrickTemplate();
//
//	for (size_t i = 0; i<4; i++)
//	{
//		for (size_t j = 0; j<4; j++)
//		{
//			if (tmp[i][j] == brick->getFormat())
//				this->field[this->cursor.getX() + i][this->cursor.getY() + j] = 'X';
//		}
//	}
//}

//Game tetris(20,20);
//
//void Field::move(const signed short moveX, const signed short moveY, Field::Point alt)
//{
//	setCursor(getCursor().getX() + moveX, getCursor().getY()+moveY);
//	clearScreen();
//	clear(alt, tetris.getActualBrick());
//	drawBrick(tetris.getActualBrick());
//	tetris.print();
//}

// Destruktor
Field::~Field()
{
	for (size_t i = 0; i<this->HEIGHT; i++)
		delete[] this->field[i];

	delete[] this->field;
}