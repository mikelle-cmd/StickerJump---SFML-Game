#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gracz.h"
using namespace std;
using namespace sf;

#define MAX_LICZBA_POZIOMOW 2

class Menusmierc: public Gracz
{
public:
	Menusmierc(float width, float height);
	~Menusmierc();

	void draw(RenderWindow& window, Gracz& gracz);
	void MoveUp();
	void MoveDown();
	int getSelectedItemS()
	{
		return selectedItemS;
	}
private:
	int selectedItemS = 0;
	Font font;
	Text menu[MAX_LICZBA_POZIOMOW];
};

