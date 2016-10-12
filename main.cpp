#include <SFML/Graphics.hpp>
#include <iostream>

#include "Display.h"
#include "Cell.h"
#include "GamePanel.h"
using namespace std;

bool is_living(vector<Cell>&, int, int);
unsigned numberOfNeighbours(vector<Cell>&, int, int);
void nextStage(vector<Cell>&, vector<Cell>&);

int main(){

	
	GamePanel * gamePanel = new GamePanel();
	Display<GamePanel> * display = new Display<GamePanel>(gamePanel);
	

	sf::Event event;

	while (display->getWindow().isOpen()){
		display->getWindow().clear();
		display->getWindow().draw(display->getSprite());

		while (display->getWindow().pollEvent(event)){
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
				cout << "x: " << event.mouseButton.x << " y: " << event.mouseButton.y << " \n";
				int coord_X = event.mouseButton.x - (event.mouseButton.x % 10);
				int coord_Y = event.mouseButton.y - (event.mouseButton.y % 10);

				gamePanel->addCell(coord_X / 10, coord_Y / 10);

			}
			if (event.type == sf::Event::Closed) 
				display->getWindow().close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				display->getWindow().close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::V){
				gamePanel->writeAll();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
				
				gamePanel->nextStage();
			}
		}

		display->drawCells();
		display->getWindow().display();
	}
	delete display;
	delete gamePanel;

	return 0;
}





