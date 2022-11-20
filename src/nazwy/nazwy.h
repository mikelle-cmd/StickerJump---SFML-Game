#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;



class Nazwy
{
public:
	Nazwy();
	~Nazwy();
	void drawsj(RenderWindow& window);
	void drawpauza(RenderWindow& window);
	void drawleavegame(RenderWindow& window);
	void drawwczytaj(RenderWindow& window);
	void drawwczytano(RenderWindow& window);
	void drawzapisz(RenderWindow& window);
	void drawzapisano(RenderWindow& window);
	void drawhelp(RenderWindow& window);
	void drawhelpnapis(RenderWindow& window);


protected:
	Text sj, pauza, leavegame, umarles, zapisz, wczytaj;
	Text zapisano, wczytano, lp, wraz, wprzt, opis, helpnapis;
	Font fontsj;

};

