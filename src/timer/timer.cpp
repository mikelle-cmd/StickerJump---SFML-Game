#include "timer.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace sf;

Timer::Timer()
{
	 timefont.loadFromFile("font.ttf");

	 czas.setFont(timefont);
	 czas.setString("Czas:");
	 czas.setCharacterSize(30);
	 czas.setFillColor(Color::White);
	 czas.setPosition(200.f, 20.f);

	 czas_smierc.setFont(timefont);
	 czas_smierc.setString("Czas");
	 czas_smierc.setCharacterSize(50);
	 czas_smierc.setFillColor(Color::White);
	 czas_smierc.setPosition(410.f, 180.f);

	 minuty.setFont(timefont);
	 minuty.setFillColor(Color::White);
	 minuty.setCharacterSize(30);
	 minuty.setPosition(250.f, 20.f);

	 minuty_smierc.setFont(timefont);
	 minuty_smierc.setFillColor(Color::White);
	 minuty_smierc.setCharacterSize(50);
	 minuty_smierc.setPosition(420.f, 230.f);

	 dwukr.setFont(timefont);
	 dwukr.setString(":");
	 dwukr.setCharacterSize(30);
	 dwukr.setFillColor(Color::White);
	 dwukr.setPosition(265.f, 20.f);

	 dwukr_smierc.setFont(timefont);
	 dwukr_smierc.setString(":");
	 dwukr_smierc.setCharacterSize(50);
	 dwukr_smierc.setFillColor(Color::White);
	 dwukr_smierc.setPosition(435.f, 230.f);

	 sekundy.setFont(timefont);
	 sekundy.setFillColor(Color::White);
	 sekundy.setCharacterSize(30);
	 sekundy.setPosition(280.f, 20.f);

	 sekundy_smierc.setFont(timefont);
	 sekundy_smierc.setFillColor(Color::White);
	 sekundy_smierc.setCharacterSize(50);
	 sekundy_smierc.setPosition(450.f, 230.f);

}

Timer::~Timer()
{
}


void Timer::count(Gracz& gracz)
{	
	if (gracz.yl <= 515)
	{
		elapsed = zegar.getElapsedTime();

		if (elapsed.asSeconds() >= 1)
		{
			sek = sek + 1;
			zegar.restart();
			if (sek >= 60)
			{
				sek = 0;
				min = min + 1;
			}
		}
		ostringstream s, m, ssmierc, msmierc;
		s << sek;
		m << min;
		ssmierc << sek;
		msmierc << min;
		sekundy.setString(s.str());
		minuty.setString(m.str());
		sekundy_smierc.setString(s.str());
		minuty_smierc.setString(m.str());
	}
}


void Timer::drawnapis(RenderWindow& window)
{
	window.draw(czas);
	window.draw(dwukr);
}

void Timer::drawczas(RenderWindow& window)
{
	window.draw(minuty);
	window.draw(sekundy);
}

void Timer::drawnapissmierc(RenderWindow& window, Gracz& gracz)
{
	if (gracz.yl >= 520)
	{
		window.draw(czas_smierc);
		window.draw(dwukr_smierc);
	}
}

void Timer::drawczassmierc(RenderWindow& window, Gracz& gracz)
{
	if (gracz.yl >= 520)
	{
		window.draw(minuty_smierc);
		window.draw(sekundy_smierc);
	}
}




