#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gracz.h"
using namespace std;
using namespace sf;

struct Point
{
	int x, y;
};

class Bloki:public Gracz
{
public:
	Bloki();
	~Bloki();
	void draw(RenderWindow& window);
	void create();
	void rollup(Gracz& gracz);
	void kolizja(Gracz& gracz);

private:
	Texture texture2;
	Sprite blok;
	Clock zegar;
	struct Point blockg[20];
};

