#include "tetromino.h"
#include <iostream>
using namespace std;

Tetromino::Tetromino(Tetromino::TETROMINO type, char format, char whitespace)
	: format(format), whitespace(whitespace), type(type), actualBrickTemplate(nullptr)
{
	this->brickFormTemplate.resize(0);
	switch (type)
	{
	case Tetromino::I:
	{
		const char t1[4][4] = {
			this->whitespace,this->format,this->whitespace,this->whitespace,
			this->whitespace,this->format,this->whitespace,this->whitespace,
			this->whitespace,this->format,this->whitespace,this->whitespace,
			this->whitespace,this->format,this->whitespace,this->whitespace,
		};
		this->generateTemplate(t1);

		const char t2[4][4] = {
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,
			this->format,this->format,this->format,this->format,
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,
		};
		this->generateTemplate(t2);
		break;
	}


	case Tetromino::J:
	{
		const char t1[4][4] = {
			this->whitespace,this->format,this->whitespace,this->whitespace,//-x
			this->whitespace,this->format,this->whitespace,this->whitespace,//-x
			this->format,this->format,this->whitespace,this->whitespace,	//xx
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,
		};
		this->generateTemplate(t1);

		const char t2[4][4] = {
			this->format,this->whitespace,this->whitespace,this->whitespace,	//#---
			this->format,this->format,this->format,this->whitespace,			//###-
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,//
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,
		};
		this->generateTemplate(t2);

		const char t3[4][4] = {
			this->whitespace,this->format,this->format,this->whitespace,    //-##
			this->whitespace,this->format,this->whitespace,this->whitespace,//-#
			this->whitespace,this->format,this->whitespace,this->whitespace,//-#
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,
		};
		this->generateTemplate(t3);

		const char t4[4][4] = {
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,//----
			this->format,this->format,this->format,this->whitespace,			//###-
			this->whitespace,this->whitespace,this->format,this->whitespace,	//--#-
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,
		};
		this->generateTemplate(t4);
		break;
	}


	case Tetromino::L:
	{
		const char t1[4][4] = {
			this->whitespace,this->format,this->whitespace,this->whitespace,//-x
			this->whitespace,this->format,this->whitespace,this->whitespace,//-x
			this->whitespace,this->format,this->format,this->whitespace,	//-xx
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,
		};
		this->generateTemplate(t1);

		const char t2[4][4] = {
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,//----
			this->format,this->format,this->format,this->whitespace,			//###-
			this->format,this->whitespace,this->whitespace,this->whitespace,	//+
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,
		};
		this->generateTemplate(t2);

		const char t3[4][4] = {
			this->format,		this->format,		this->whitespace,	this->whitespace,//##
			this->whitespace,	this->format,		this->whitespace,	this->whitespace,//-#
			this->whitespace,	this->format,		this->whitespace,	this->whitespace,//-#
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
		};
		this->generateTemplate(t3);

		const char t4[4][4] = {
			this->whitespace,	this->whitespace,	this->format,		this->whitespace,//--#-
			this->format,		this->format,		this->format,		this->whitespace,//###-
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,//----
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
		};
		this->generateTemplate(t4);
		break;
	}


	case Tetromino::O:
	{
		const char t1[4][4] = {
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,	//---
			this->whitespace,this->format,this->format,this->whitespace,			//-##-
			this->whitespace,this->format,this->format,this->whitespace,			//-##-
			this->whitespace,this->whitespace,this->whitespace,this->whitespace,
		};
		this->generateTemplate(t1);
		break;
	}
	case Tetromino::S:
	{
		const char t1[4][4] = {
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,//--
			this->whitespace,	this->format,		this->format,		this->whitespace,//-##
			this->format,		this->format,		this->whitespace,	this->whitespace,//##
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
		};
		this->generateTemplate(t1);

		const char t2[4][4] = {
			this->whitespace,	this->format,		this->whitespace,	this->whitespace,//-#--
			this->whitespace,	this->format,		this->format,		this->whitespace,//-##-
			this->whitespace,	this->whitespace,	this->format,		this->whitespace,//--#-
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
		};
		this->generateTemplate(t2);
		break;
	}
	case Tetromino::T:
	{
		const char t1[4][4] = {
			this->whitespace,	this->format,		this->whitespace,	this->whitespace,// #
			this->format,		this->format,		this->format,		this->whitespace,//###
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,//
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
		};
		this->generateTemplate(t1);

		const char t2[4][4] = {
			this->whitespace,	this->format,		this->whitespace,	this->whitespace,//-#--
			this->whitespace,	this->format,		this->format,		this->whitespace,//-##-
			this->whitespace,	this->format,		this->whitespace,	this->whitespace,//-#--
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
		};
		this->generateTemplate(t2);

		const char t3[4][4] = {
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,//--
			this->format,		this->format,		this->format,		this->whitespace,//###
			this->whitespace,	this->format,		this->whitespace,	this->whitespace,//-#
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
		};
		this->generateTemplate(t3);

		const char t4[4][4] = {
			this->whitespace,	this->format,		this->whitespace,	this->whitespace,//-#--
			this->format,		this->format,		this->whitespace,	this->whitespace,//##-
			this->whitespace,	this->format,		this->whitespace,	this->whitespace,//-#-
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
		};
		this->generateTemplate(t4);
		break;
	}
	case Tetromino::Z:
	{
		const char t1[4][4] = {
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,//--
			this->format,		this->format,		this->whitespace,	this->whitespace,//##
			this->whitespace,	this->format,		this->format,		this->whitespace,//-##
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
		};
		this->generateTemplate(t1);

		const char t2[4][4] = {
			this->whitespace,	this->whitespace,	this->format,		this->whitespace,//--#--
			this->whitespace,	this->format,		this->format,		this->whitespace,//-##-
			this->whitespace,	this->format,		this->whitespace,	this->whitespace,//-#-
			this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
		};
		this->generateTemplate(t2);
		break;
	}
	}
		
	this->actualBrickTemplate = this->brickFormTemplate[0];
	this->actualBrickIndex = 0;
}

void Tetromino::generateTemplate(const char t[4][4])
{
	this->brickFormTemplate.push_back(new char*[4]);

	for (size_t i = 0; i < 4; i++)
	{
		this->brickFormTemplate[brickFormTemplate.size()-1][i] = new char[4];
	}
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			this->brickFormTemplate[brickFormTemplate.size() - 1][i][j] = t[i][j];
		}
	}
	
}

void Tetromino::print() const {
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << this->actualBrickTemplate[i][j];
		}
		std::cout << endl;
	}
}

void Tetromino::printAllTemplates() const {
	for (size_t i = 0; i < this->brickFormTemplate.size(); i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t k = 0; k < 4; k++)
			{
				std::cout << this->brickFormTemplate[i][j][k];
			}
			std::cout << endl;
		}
	}
}

void Tetromino::rotate(int key) {
	int index = this->actualBrickIndex;
	switch (key)
	{
	case 'a':
	case 'A':
		index = ((index - 1 ) + this->brickFormTemplate.size()) % this->brickFormTemplate.size();
		this->actualBrickIndex = index;
		this->actualBrickTemplate = this->brickFormTemplate[index];
		break;

	case 'd':
	case 'D':
		index = (index + 1) % this->brickFormTemplate.size();
		this->actualBrickIndex = index;
		this->actualBrickTemplate = this->brickFormTemplate[index];
		break;
	}
}


Tetromino::~Tetromino()
{
	for (size_t i = 0; i < this->brickFormTemplate.size(); i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			delete[](this->brickFormTemplate[i][j]);
		}

		delete[](this->brickFormTemplate[i]);

	}
}
	
