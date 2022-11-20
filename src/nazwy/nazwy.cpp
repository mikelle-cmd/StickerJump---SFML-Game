#include "nazwy.h"
#include <iostream>


using namespace std;
using namespace sf;

Nazwy::Nazwy()
{
	fontsj.loadFromFile("font.ttf");

	sj.setFont(fontsj);
	sj.setString("Stick Jumper");
	sj.setCharacterSize(80);
	sj.setFillColor(Color::White);
	sj.setPosition(220.f, 40.f);

	pauza.setFont(fontsj);
	pauza.setString("PAUZA");
	pauza.setCharacterSize(60);
	pauza.setFillColor(Color::White);
	pauza.setPosition(310.f, 90.f);

	leavegame.setFont(fontsj);
	leavegame.setString("Czy chcesz opuscic gre ?");
	leavegame.setCharacterSize(50);
	leavegame.setFillColor(Color::White);
	leavegame.setPosition(210.f, 170.f);

	umarles.setFont(fontsj);
	umarles.setString("Umarles !");
	umarles.setCharacterSize(70);
	umarles.setFillColor(Color::White);
	umarles.setPosition(270.f, 80.f);

	wczytaj.setFont(fontsj);
	wczytaj.setString("wczytaj - L"); //load
	wczytaj.setCharacterSize(55);
	wczytaj.setFillColor(Color::White);
	wczytaj.setPosition(270.f, 500.f);

	wczytano.setFont(fontsj);
	wczytano.setString("wczytano"); 
	wczytano.setCharacterSize(35);
	wczytano.setFillColor(Color::White);
	wczytano.setPosition(600.f, 45.f);

	zapisz.setFont(fontsj);
	zapisz.setString("zapis - z  |"); //zapisz
	zapisz.setCharacterSize(40);
	zapisz.setFillColor(Color::White);
	zapisz.setPosition(350.f, 15.f);

	zapisano.setFont(fontsj);
	zapisano.setString("zapisano"); 
	zapisano.setCharacterSize(40);
	zapisano.setFillColor(Color::White);
	zapisano.setPosition(600.f, 45.f);

	lp.setFont(fontsj);
	lp.setString("A,D - Lewo, Prawo");
	lp.setCharacterSize(40);
	lp.setFillColor(Color::White);
	lp.setPosition(150.f, 370.f);

	wraz.setFont(fontsj);
	wraz.setString("W(klikniecie) - skok");
	wraz.setCharacterSize(40);
	wraz.setFillColor(Color::White);
	wraz.setPosition(150.f, 320.f);

	wprzt.setFont(fontsj);
	wprzt.setString("W(przytrzymanie) - podwojny skok");
	wprzt.setCharacterSize(40);
	wprzt.setFillColor(Color::White);
	wprzt.setPosition(150.f, 270.f);

	opis.setFont(fontsj);
	opis.setString("Spiesz sie || Zbieraj monety || Przezyj");
	opis.setCharacterSize(40);
	opis.setFillColor(Color::White);
	opis.setPosition(150.f, 200.f);

	helpnapis.setFont(fontsj);
	helpnapis.setString("Help - F1");
	helpnapis.setCharacterSize(40);
	helpnapis.setFillColor(Color::White);
	helpnapis.setPosition(480.f, 15.f);
}	

Nazwy::~Nazwy()
{
}

void Nazwy::drawsj(RenderWindow& window)
{
	window.draw(sj);
}

void Nazwy::drawpauza(RenderWindow& window)
{
	window.draw(pauza);
}

void Nazwy::drawleavegame(RenderWindow& window)
{
	window.draw(leavegame);
}

void Nazwy::drawwczytaj(RenderWindow& window)
{
	window.draw(wczytaj);
}

void Nazwy::drawzapisz(RenderWindow& window)
{
	window.draw(zapisz);
}

void Nazwy::drawwczytano(RenderWindow& window)
{
		window.draw(wczytano);
}

void Nazwy::drawzapisano(RenderWindow& window)
{
	window.draw(zapisano);
}

void Nazwy::drawhelp(RenderWindow& window)
{
	window.draw(lp);
	window.draw(wraz);
	window.draw(wprzt);
	window.draw(opis);
}

void Nazwy::drawhelpnapis(RenderWindow& window)
{
	window.draw(helpnapis);
}