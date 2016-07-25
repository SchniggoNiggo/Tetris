#ifndef FIELD_H
#define FIELD_H

class Field {
public:
	Field(size_t HEIGHT, size_t WIDHT);


	void print() const;
	~Field();
private:
	char **field;

	const size_t HEIGHT;
	const size_t WIDHT;
};
#endif