#include "bloki.h"
#include <iostream>


using namespace std;
using namespace sf;

Bloki::Bloki()
{
	texture2.loadFromFile("block.png");
	blok.setTexture(texture2);
}

Bloki::~Bloki()
{
}

void Bloki::create()
{
	for (int i = 0; i < 10; i++)
	{
		blockg[i].x = rand() % 800;
		blockg[i].y = rand() % 600;
	}
}

void Bloki::rollup(Gracz& gracz)
{
	if (gracz.yl < gracz.h)
	{
		for (int i = 0; i < 10; i++)
		{
			gracz.yl = gracz.h;
			blockg[i].y = blockg[i].y - gracz.dyl;
			if (blockg[i].y > 600)
			{
				blockg[i].y = 0;
				blockg[i].x = rand() % 800;
			}
		}
	}
}

void Bloki::kolizja(Gracz& gracz)
{
	for (int i = 0; i < 10; i++)
	{
		if ((gracz.xl + 50 > blockg[i].x) && (gracz.xl + 68 < blockg[i].x + 68) && (gracz.yl + 87 > blockg[i].y) && (gracz.yl + 87 < blockg[i].y + 14) && (gracz.dyl > 0))
		{
			gracz.dyl = 0;

			if (zegar.getElapsedTime().asMilliseconds() >= 1200.0f && (Keyboard::isKeyPressed(Keyboard::W)))
			{
				gracz.dyl = -10;
				zegar.restart();
			}
		}
	}
}

void Bloki::draw(RenderWindow& window)
{
	for (int i = 0; i < 10; i++)
	{
		blok.setPosition(blockg[i].x, blockg[i].y);
		window.draw(blok);
	}
}

