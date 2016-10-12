#include "Cell.h"

Cell::Cell() {

}
Cell::Cell(int x, int y) {
	this->x = x;
	this->y = y;
}
void Cell::setX(int x){
	this->x = x;
}

void Cell::setY(int y) {
	this->y = y;
}

int Cell::getX() const {
	return x;
}

int Cell::getY() const {
	return y;
}