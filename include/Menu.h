#ifndef MENU_H
#define MENU_H
#endif // MENU_H
#pragma once
#include "SFML/Graphics.hpp"
#define MAX_NUMBER_OF_ITEMS 3
using namespace sf;
class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};


