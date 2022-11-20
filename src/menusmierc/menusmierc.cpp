#include "menusmierc.h"
#include <iostream>

using namespace std;
using namespace sf;

Menusmierc::Menusmierc(float width, float height)
{
	if (!font.loadFromFile("font.ttf"))
	{
		cout << "Blad czcionki" << endl;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setCharacterSize(45);
	menu[0].setString("Ostatnia szansa !");
	menu[0].setPosition(Vector2f(width / 2.8, height / (MAX_LICZBA_POZIOMOW + 1) * 1.6));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setCharacterSize(45);
	menu[1].setString("Wyjdz z gry");
	menu[1].setPosition(Vector2f(width / 2.4, height / (MAX_LICZBA_POZIOMOW + 1) * 2.1));
}

Menusmierc::~Menusmierc()
{
}

void Menusmierc::draw(RenderWindow& window, Gracz& gracz)
{
	for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
	{
		if (gracz.yl >= 520)
			window.draw(menu[i]);
	}
}

void Menusmierc::MoveUp()
{
	if (selectedItemS >= 0 && selectedItemS < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItemS].setFillColor(Color::White);
		selectedItemS--;
		if (selectedItemS < 0)
			selectedItemS = MAX_LICZBA_POZIOMOW - 1;
		menu[selectedItemS].setFillColor(Color::Red);
	}
}

void Menusmierc::MoveDown()
{
	if (selectedItemS >= 0 && selectedItemS < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItemS].setFillColor(Color::White);
		selectedItemS++;
		if (selectedItemS >= MAX_LICZBA_POZIOMOW)
			selectedItemS = 0;
		menu[selectedItemS].setFillColor(Color::Red);
	}
}
