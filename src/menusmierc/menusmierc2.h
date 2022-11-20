#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gracz.h"
using namespace std;
using namespace sf;

#define MAX_LICZBA_POZIOMOW_2 1

class Menusmierc2 : public Gracz
{
public:
	Menusmierc2(float width, float height);
	~Menusmierc2();

	void draw(RenderWindow& window, Gracz& gracz);
	void MoveUp();
	void MoveDown();
	int getSelectedItemS2()
	{
		return selectedItemS2;
	}
private:
	int selectedItemS2 = 0;
	Font font;
	Text menu[MAX_LICZBA_POZIOMOW_2];
};

