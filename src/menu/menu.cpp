#include "menu.h"
#include <iostream>


using namespace std;
using namespace sf;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("font.ttf"))
	{
		cout << "Blad czcionki" << endl;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setCharacterSize(45);
	menu[0].setString("Graj");
	menu[0].setPosition(Vector2f(width / 2.2, height / (MAX_LICZBA_POZIOMOW + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setCharacterSize(45);
	menu[1].setString("Wyjscie");
	menu[1].setPosition(Vector2f(width / 2.2, height / (MAX_LICZBA_POZIOMOW + 1) * 1.5));
}

Menu::~Menu()
{
}

void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItem >= 0 && selectedItem < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItem].setFillColor(Color::White);
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = MAX_LICZBA_POZIOMOW - 1;
		menu[selectedItem].setFillColor(Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItem >= 0 && selectedItem < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItem].setFillColor(Color::White);
		selectedItem++;
		if (selectedItem >= MAX_LICZBA_POZIOMOW)
			selectedItem = 0;
		menu[selectedItem].setFillColor(Color::Red);
	}
}