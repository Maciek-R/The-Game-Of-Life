#include <vector>
#include <iostream>
#include "GamePanel.h"
#include "Cell.h"

GamePanel::~GamePanel() {
	Cells.clear();
	NextCells.clear();
}
void GamePanel::addCell(int x, int y) {

	Cell cell(x, y);
	Cells.push_back(cell);
}
void GamePanel::nextStage() {
		for (int j = 0; j<60; ++j)
			for (int i = 0; i<80; ++i)
			{
				bool Q = isLiving(i, j);

				unsigned countNeighbours = numberOfNeighbours(i, j);

				if (Q == true) {
					if (countNeighbours == 2 || countNeighbours == 3) {
						Cell cell(i, j);
						NextCells.push_back(cell);
					}
				}
				if (Q == false) {
					if (countNeighbours == 3) {
						Cell cell(i, j);
						NextCells.push_back(cell);
					}
				}
			}
		Cells.clear();

		for (unsigned w = 0; w<NextCells.size(); ++w) {
			Cell cell(NextCells[w].getX(), NextCells[w].getY());
			Cells.push_back(cell);
		}
		NextCells.clear();
}
std::vector<Cell>* GamePanel::getCells() {
	return &Cells;
}

void GamePanel::writeAll() {
	for (unsigned f = 0; f<Cells.size(); f++) {
		std::cout << f + 1 << ": " << Cells[f].getX() << " " << Cells[f].getY() << std::endl;
	}
}
bool GamePanel::isLiving(int i, int j) {
	for (unsigned q = 0; q < Cells.size(); ++q) {
		if (Cells[q].getX() == i && Cells[q].getY() == j) return true;
	}
	return false;
}
unsigned GamePanel::numberOfNeighbours(int i, int j) {
	unsigned count = 0;

	if (i - 1 >= 0 && j - 1 >= 0) if (isLiving(i - 1, j - 1)) ++count;
	if (i - 1 >= 0) if (isLiving(i - 1, j)) ++count;
	if (i - 1 >= 0 && j + 1 >= 0) if (isLiving(i - 1, j + 1)) ++count;
	if (j - 1 >= 0) if (isLiving(i, j - 1)) ++count;
	if (j + 1 >= 0) if (isLiving(i, j + 1)) ++count;
	if (i + 1 >= 0 && j - 1 >= 0) if (isLiving(i + 1, j - 1)) ++count;
	if (i + 1 >= 0) if (isLiving(i + 1, j)) ++count;
	if (i + 1 >= 0 && j + 1 >= 0) if (isLiving(i + 1, j + 1)) ++count;

	return count;
}