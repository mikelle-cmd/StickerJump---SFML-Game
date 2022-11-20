#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "nazwy.h"

using namespace std;
using namespace sf;

class Gracz: public Nazwy
{
public:
	Gracz();
	~Gracz();
	void drawserce(RenderWindow& window);
	void drawserce2(RenderWindow& window);
	void draw(RenderWindow& window);
	void drawumarles(RenderWindow& window);
	void ruch();
	void pozycja();
	void animacjaludzika();
	void smierc();
	void wroc();

	Image anim, skok, imgserce;
	Texture texture1, texture3, texture_serce;
	IntRect ksztaltludzika; 
	Sprite ludzik, ludzikskok, serce, serce2;
	Clock zegar2, zegar3, zegar4, zegar5;
	int xl = 100, yl = 100, h = 200, temp = 0;
	float dxl = 0, dyl = 0;
};


