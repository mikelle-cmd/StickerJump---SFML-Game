#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#define MAX_LICZBA_POZIOMOW 2

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getSelectedItem()
	{
		return selectedItem;
	}
private:
	int selectedItem = 0;
	Font font;
	Text menu[MAX_LICZBA_POZIOMOW]; 
};