#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Gracz.h"

using namespace std;
using namespace sf;

class Timer: public Gracz
{
public:
	Timer();
	~Timer();
	void drawnapis(RenderWindow& window);
	void drawczas(RenderWindow& window);
	void drawnapissmierc(RenderWindow& window, Gracz& gracz);
	void drawczassmierc(RenderWindow& window, Gracz& gracz);
	void count(Gracz& gracz);

private:
	Time elapsed;
	int min = 0, sek = 0, temp = 0;
	Clock zegar;
	Text czas, minuty, sekundy, dwukr, czas_smierc, minuty_smierc, sekundy_smierc, dwukr_smierc;
	Font timefont;

};

