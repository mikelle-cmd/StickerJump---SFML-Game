#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gracz.h"

using namespace std;
using namespace sf;

class Bot: public Gracz
{
public:
	Bot(float x_in, float y_in, RenderWindow& window);
	void przesun(float *x_in, float *y_in);
	Sprite getBot()
	{
		return pSprite;
	}
	void animuj();
	void kolizja(Gracz &gracz);

private:
	Image image;
	Vector2f position;
	float xVel = 1, yVel = 1;
	Texture tekstura;
	Sprite pSprite;
	Vector2f rozmiar_okna;
};

