#ifndef GAMEPANEL_H
#define GAMEPANEL_H
#include "Cell.h"
class GamePanel {
private:
	std::vector<Cell> Cells;
	std::vector<Cell> NextCells;

	bool isLiving(int, int);
	unsigned numberOfNeighbours(int, int);

public:

	virtual ~GamePanel();
	void addCell(int, int);
	void nextStage();
	void writeAll();

	std::vector<Cell> * getCells();
};

#endif