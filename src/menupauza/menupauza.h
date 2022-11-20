#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#define MAX_LICZBA_POZIOMOW 2

class Menupauza
{
public:
	Menupauza(float width, float height);
	~Menupauza();

	void draw(RenderWindow& window);
	void MoveLeft();
	void MoveRight();
	int getSelectedItemK()
	{
		return selectedItemK;
	}
private:
	int selectedItemK = 0;
	Font font;
	Text menu[MAX_LICZBA_POZIOMOW]; //2 opcje
};

