#include "menupauza.h"
#include <iostream>

using namespace std;
using namespace sf;

Menupauza::Menupauza(float width, float height)
{
	if (!font.loadFromFile("font.ttf"))
	{
		cout << "Blad czcionki" << endl;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setCharacterSize(45);
	menu[0].setString("Tak");
	menu[0].setPosition(Vector2f(width / 2.8, height / (MAX_LICZBA_POZIOMOW + 1) * 1.3));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setCharacterSize(45);
	menu[1].setString("Nie");
	menu[1].setPosition(Vector2f(width / 1.8, height / (MAX_LICZBA_POZIOMOW + 1) * 1.3));
}

Menupauza::~Menupauza()
{
}

void Menupauza::MoveLeft()
{
	if (selectedItemK >= 0 && selectedItemK < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItemK].setFillColor(Color::White);
		selectedItemK--;
		if (selectedItemK < 0)
			selectedItemK = MAX_LICZBA_POZIOMOW - 1;
		menu[selectedItemK].setFillColor(Color::Red);
	}
}

void Menupauza::MoveRight()
{
	if (selectedItemK >= 0 && selectedItemK < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItemK].setFillColor(Color::White);
		selectedItemK++;
		if (selectedItemK >= MAX_LICZBA_POZIOMOW)
			selectedItemK = 0;
		menu[selectedItemK].setFillColor(Color::Red);
	}
}

void Menupauza::draw(RenderWindow& window)
{
		for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
		{
			 window.draw(menu[i]);
		}
}