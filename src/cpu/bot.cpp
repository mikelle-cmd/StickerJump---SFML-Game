#include "bot.h"
#include <iostream>


using namespace std;
using namespace sf;

Bot::Bot(float x_in, float y_in, RenderWindow& window)
{
	position.x = x_in;
	position.y = y_in;
	image.loadFromFile("spike.png");
	image.createMaskFromColor(Color::White);
	tekstura.loadFromImage(image);
	pSprite.setTexture(tekstura);
	pSprite.setPosition(position);
	pSprite.setScale(0.5, 0.5);
	rozmiar_okna = Vector2f(window.getSize().x + 50, window.getSize().y + 50);
}

void Bot::przesun(float *x_in, float *y_in)
{
	Vector2f pos;
	pos.x = *x_in;
	pos.y = *y_in;
	pSprite.move(pos);
	position = pSprite.getPosition();
}

void Bot::kolizja(Gracz &gracz)
{
	if (position.x <= 0)
		xVel = 1;
	if (position.y <= 0)
		yVel = 1;
	if (position.x >= rozmiar_okna.x - tekstura.getSize().x)
		xVel = -1;
	if (position.y >= rozmiar_okna.y - tekstura.getSize().y)
		yVel = -1;

	if ((gracz.xl >= position.x - 30) && (gracz.xl <= position.x + 30) && (gracz.yl >= position.y - 30) && (gracz.yl <= position.y + 30))
	{
		gracz.xl = gracz.xl + 80;
	}
}

void Bot::animuj()
{
	przesun(&xVel, &yVel);
}