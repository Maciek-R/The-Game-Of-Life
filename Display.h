#ifndef DISPLAY_H
#define DISPLAY_H

template<typename T>
class Display {

private:
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape rectangle;
	T * gamePanel;

public:
	const static int WIDTH = 800;
	const static int HEIGHT = 600;

	
	Display(T*);
	virtual ~Display();
	sf::RenderWindow& getWindow();
	sf::Sprite& getSprite();
	void drawCells();
};



#endif