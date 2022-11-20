#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gracz.h"
#include <string>
#include <fstream>
using namespace std;
using namespace sf;

struct Punkt
{
	int x, y;
};

class Monety: public Gracz
{
public:
	Monety();
	~Monety();

	void draw(RenderWindow& window);
	void drawnapis(RenderWindow& window);
	void drawpunkty(RenderWindow& window);
	void drawnapissmierc(RenderWindow& window, Gracz& gracz);
	void drawpunktysmierc(RenderWindow& window, Gracz& gracz);

	void animacjamonety();
	void dodaj_monety_kolizja(Gracz& gracz);
	void create();
	void rollup(Gracz& gracz);
	void zapisz();
	void wczytaj();


protected:
	Image mon;
	Texture texturemon;
	Text score, score_text, score_smierc, score_text_smierc;
	Font scorefont;
	int current_score = 0;
	IntRect ksztaltmonety;
	Clock zegar1, zegar2;
	Sprite moneta;
	Punkt monety[10];
	fstream plik;
	string linia;
};



