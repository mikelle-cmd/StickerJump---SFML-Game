#include "menusmierc2.h"
#include <iostream>

using namespace std;
using namespace sf;

Menusmierc2::Menusmierc2(float width, float height)
{
	if (!font.loadFromFile("font.ttf"))
	{
		cout << "Blad czcionki" << endl;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setCharacterSize(45);
	menu[0].setString("Wyjdz z gry");
	menu[0].setPosition(Vector2f(width / 2.4, height / (MAX_LICZBA_POZIOMOW_2 + 1) * 1.1));
}

Menusmierc2::~Menusmierc2()
{
}

void Menusmierc2::draw(RenderWindow& window, Gracz& gracz)
{
	for (int i = 0; i < MAX_LICZBA_POZIOMOW_2; i++)
	{
		if (gracz.yl >= 520)
		{
			window.draw(menu[i]);
		}		
	}
}

void Menusmierc2::MoveUp()
{
	if (selectedItemS2 >= 0 && selectedItemS2 < MAX_LICZBA_POZIOMOW_2)
	{
		menu[selectedItemS2].setFillColor(Color::White);
		selectedItemS2--;
		if (selectedItemS2 < 0)
			selectedItemS2 = MAX_LICZBA_POZIOMOW_2 - 1;
		menu[selectedItemS2].setFillColor(Color::Red);
	}
}

void Menusmierc2::MoveDown()
{
	if (selectedItemS2 >= 0 && selectedItemS2 < MAX_LICZBA_POZIOMOW_2)
	{
		menu[selectedItemS2].setFillColor(Color::White);
		selectedItemS2++;
		if (selectedItemS2 >= MAX_LICZBA_POZIOMOW_2)
			selectedItemS2 = 0;
		menu[selectedItemS2].setFillColor(Color::Red);
	}
}