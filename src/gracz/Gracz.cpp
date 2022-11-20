#include "Gracz.h"
#include <iostream>

using namespace std;
using namespace sf;

Gracz::Gracz()
{
	anim.loadFromFile("ludzikanim5.png");
	anim.createMaskFromColor(Color::White);
	texture1.loadFromImage(anim);

	skok.loadFromFile("ludzikskok2.png");
	skok.createMaskFromColor(Color::White);
	texture3.loadFromImage(skok);

	ludzikskok.setTexture(texture3);
	ludzikskok.setScale(0.7, 0.7);
	ludzik.setTexture(texture1);
	ludzik.setTextureRect(ksztaltludzika);
	ludzik.setScale(0.7, 0.7);

	imgserce.loadFromFile("serce12.png");
	imgserce.createMaskFromColor(Color::White);
	texture_serce.loadFromImage(imgserce);
	serce.setTexture(texture_serce);
	serce2.setTexture(texture_serce);
	serce.setPosition(650.f, 15.f);
	serce.setScale(0.08, 0.08);
	serce2.setPosition(610.f, 15.f);
	serce2.setScale(0.08, 0.08);

	ksztaltludzika.left = 200;
	ksztaltludzika.top = 0;
	ksztaltludzika.width = 120;
	ksztaltludzika.height = 130;
}

Gracz::~Gracz()
{
}
void Gracz::drawserce(RenderWindow& window)
{
	window.draw(serce);
}

void Gracz::drawserce2(RenderWindow& window)
{
	window.draw(serce2);
}

void Gracz::draw(RenderWindow& window)
{
	if (dyl == 0)
	{
		window.draw(ludzik);
	}
	else
	{
		window.draw(ludzikskok);
	}
		
}

void Gracz::drawumarles(RenderWindow& window)
{
	if (yl >= 520)
	{
		window.draw(umarles);		
	}
}

void Gracz::smierc()
{
	if (yl >= 498 && zegar4.getElapsedTime().asMilliseconds() <= 6000.0f)
	{
		dyl = 0;
	}

	if (yl >= 850)
	{
		dyl = 0;
	}
}

void Gracz::animacjaludzika()
{
	if (zegar2.getElapsedTime().asMilliseconds() > 400.0f)
	{
		if (ksztaltludzika.left == 400)
		{
			ksztaltludzika.left = 0;
		}
		else
		{
			ksztaltludzika.left += 200;
		}

		ludzik.setTextureRect(ksztaltludzika);
		zegar2.restart();
	}
}

void Gracz::pozycja()
{
	ludzik.setPosition(xl, yl);
	ludzikskok.setPosition(xl, yl);
}

void Gracz::wroc()
{
	if (temp == 0)
	{
		if (yl >= 600)
		{
			dyl = -20;
		}
	}

	if (yl <= 400)
		temp = 1;
}


void Gracz::ruch()
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		xl += 3;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		xl -= 3;
	}

	if (xl < -13)
		xl = -13;

	if (xl > 650)
		xl = 650;


	if (zegar3.getElapsedTime().asMilliseconds() >= 2500.0f && (Keyboard::isKeyPressed(Keyboard::W)))
	{
		dyl = -10;
		zegar3.restart();
	}

	//szybkosc skoku 
	dyl += 0.2; 
	yl += dyl;

}




	
		





