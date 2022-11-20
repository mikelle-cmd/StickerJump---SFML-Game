#include "monety.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace sf;

Monety::Monety()
{
	mon.loadFromFile("coinanim.png");
	mon.createMaskFromColor(Color::White);
	texturemon.loadFromImage(mon);
	moneta.setTexture(texturemon);
	moneta.setScale(0.25, 0.25);
	moneta.setTextureRect(ksztaltmonety);

	ksztaltmonety.left = 130;
	ksztaltmonety.top = 0;
	ksztaltmonety.width = 115;
	ksztaltmonety.height = 130;

	scorefont.loadFromFile("font.ttf");

	score.setFont(scorefont);
	score.setString("Monety:");
	score.setCharacterSize(30);
	score.setFillColor(Color::White);
	score.setPosition(50.f, 20.f);

	score_text.setFont(scorefont);
	score_text.setFillColor(Color::White);
	score_text.setCharacterSize(30);
	score_text.setPosition(130.f, 20.f);

	score_smierc.setFont(scorefont);
	score_smierc.setString("Pieniadze");
	score_smierc.setCharacterSize(50);
	score_smierc.setFillColor(Color::White);
	score_smierc.setPosition(190.f, 180.f);

	score_text_smierc.setFont(scorefont);
	score_text_smierc.setFillColor(Color::White);
	score_text_smierc.setCharacterSize(50);
	score_text_smierc.setPosition(255.f, 230.f);

}

Monety::~Monety()
{
}

void Monety::drawnapis(RenderWindow& window)
{
	window.draw(score);
}

void Monety::drawpunkty(RenderWindow& window)
{
	window.draw(score_text);
}

void Monety::drawnapissmierc(RenderWindow& window, Gracz& gracz)
{
	if (gracz.yl >= 520)
	window.draw(score_smierc);
}

void Monety::drawpunktysmierc(RenderWindow& window, Gracz& gracz)
{
	if (gracz.yl >= 520)
	{
		window.draw(score_text_smierc);
	}
}

void Monety::dodaj_monety_kolizja(Gracz& gracz)
{
	for (int j = 0; j < 10; j++)
	{
		if ((gracz.xl + 58 > monety[j].x) && (gracz.xl + 40 < monety[j].x + 33)
			&& (gracz.yl + 85 > monety[j].y) && (gracz.yl + 10 < monety[j].y + 25)) 		
		{
			current_score = current_score + 1;
			monety[j].x = 600;
			monety[j].y = 600;
		}	
	}
	stringstream s, smierc;
	s << current_score;
	smierc << current_score;
	score_text.setString(s.str());
	score_text_smierc.setString(smierc.str());
}

void Monety::create()
{
	for (int j = 0; j < 10; j++)
	{
		monety[j].x = rand() % 800;
		monety[j].y = rand() % 600;
	}
}

void Monety::rollup(Gracz& gracz)
{
	if (gracz.yl == gracz.h)
	{
		for (int j = 0; j < 10; j++)
		{
			gracz.yl = gracz.h;
			monety[j].y = monety[j].y - gracz.dyl;
			if (monety[j].y > 600)
			{
				monety[j].y = 0;
				monety[j].x = rand() % 800;
			}
		}
	}
}


void Monety::draw(RenderWindow& window)
{
	for (int j = 0; j < 10; j++)
	{
		moneta.setPosition(monety[j].x, monety[j].y);
		window.draw(moneta);
	}
}

void Monety::animacjamonety()
{
	for (int j = 0; j < 10; j++)
	{
		if (zegar1.getElapsedTime().asMilliseconds() > 100.0f)
		{
			if (ksztaltmonety.left == 780)
			{
				ksztaltmonety.left = 0;
			}
			else
			{
				ksztaltmonety.left += 130;
			}

			moneta.setTextureRect(ksztaltmonety);
			zegar1.restart();
		}
	}
}

void Monety::zapisz()
{
	plik.open("monety.txt", ios::out);

	if (plik.good() == true) 
	{
		plik << current_score;
		plik.flush();
		plik.close();
	}
	else 
		cout << "Brak dostepu do pliku " << endl;


}

void Monety::wczytaj()
{
	plik.open("monety.txt", ios::in);

	if (plik.good() == true)
	{
		plik >> current_score;
		plik.flush();
		plik.close();
	}
	else
		cout << "Brak dostepu do pliku " << endl;

}


