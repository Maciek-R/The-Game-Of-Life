#include <SFML/Graphics.hpp>
#include "Display.h"
#include "GamePanel.h"

template<typename T>
Display<T>::Display(T* gamePanel) {
	window.create(sf::VideoMode(Display::WIDTH, Display::HEIGHT), "The Game Of Life");
	texture.loadFromFile("res/qwerty.png");
	sprite.setTexture(texture);
	rectangle.setSize(sf::Vector2f(9, 9));
	rectangle.setOutlineThickness(1);
	rectangle.setFillColor(sf::Color(255, 255, 0));
	this->gamePanel = gamePanel;
}
template<typename T>
Display<T>::~Display() {
	gamePanel = NULL;
	window.close();
}

template<typename T>
sf::RenderWindow& Display<T>::getWindow() {
	return window;
}
template<typename T>
sf::Sprite& Display<T>::getSprite() {
	return sprite;
}

template<typename T>
void Display<T>::drawCells() {
	
	for (unsigned i = 0; i < gamePanel->getCells()->size(); ++i) {
		int x = (*(gamePanel->getCells()))[i].getX() *10;
		int y = (*(gamePanel->getCells()))[i].getY() *10;
		rectangle.setPosition(static_cast<float>(x), static_cast<float>(y));
		window.draw(rectangle);
	}
	
}


template class Display<GamePanel>;