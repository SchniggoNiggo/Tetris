#ifndef FIELD_H
#define FIELD_H

class Field {
public:

	struct Point
	{
		Point()
			: x(0), y(0)
		{
		}

		void setY(unsigned short y) {
			this->y = y;
		}

		void setX(unsigned short x) {
			this->x = x;
		}

		unsigned short getY() const {
			return this->y;
		}

		unsigned short getX() const {
			return this->x;
		}

		unsigned short x;
		unsigned short y;

	};

	Field(size_t HEIGHT, size_t WIDHT);

	void print() const;

	~Field();
private:
	char **field;
	Point cursor;
	const size_t HEIGHT;
	const size_t WIDHT;
};
#endif