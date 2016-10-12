#ifndef CELL_H
#define CELL_H

class Cell {
private:
	int x;
	int y;
public:
	Cell();
	Cell(int, int);
	void setX(int);
	void setY(int);

	int getX() const;
	int getY() const;
};

#endif