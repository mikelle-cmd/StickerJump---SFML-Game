#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "menu.h"
#include "menupauza.h"
#include "menusmierc.h"
#include "menusmierc2.h"
#include "bot.h"
#include "nazwy.h"
#include "Gracz.h"
#include "podest.h"
#include "monety.h"
#include "bloki.h"
#include "timer.h"

using namespace std;
using namespace sf;

int main()
{
	srand(time(NULL));
	//wszelkie zmienne
	RenderWindow window(VideoMode(700, 600), "Stick Jumper");
	window.setFramerateLimit(60);

	//zmienne menu i menukoniec
	Menu menu(window.getSize().x, window.getSize().y);
	Menupauza menupauza(window.getSize().x, window.getSize().y);
	Menusmierc menusmierc(window.getSize().x, window.getSize().y);
	Menusmierc2 menusmierc2(window.getSize().x, window.getSize().y);
	int wybrana_opcja = 0;
	int wybrana_opcja_pauza = 0;
	int wybrana_opcja_smierc = 0, wybrana_opcja_smierc_2 = 0;
	int smierc = 0, load = 0, save = 0, stop = 0;

	Nazwy nazwy;
	Gracz gracz;
	Bloki blok;
	Monety moneta;
	Podest podest;
	Timer timer;

	//zmienne bot
	Bot bot1(50, 10, window), bot2(400, 10, window);

	Clock zegar, zegar5, pauza, reset, zegarload, zegarsave;

	//zmienne ludzik, bloki
	Image ludzikme;
	ludzikme.loadFromFile("ludzikskok2.png");
	ludzikme.createMaskFromColor(Color::White);

	Texture texture5, texture6, texture7;
	texture5.loadFromImage(ludzikme);
	texture6.loadFromFile("block.png");
	texture7.loadFromFile("background1.png");

	Sprite ludzikmenu(texture5), blockmenu(texture6), tlo(texture7);


	//ludzik i bloki na menu
	ludzikmenu.setPosition(100.f, 180.f);
	ludzikmenu.setScale(0.8, 0.8);
	blockmenu.setPosition(132.f, 270.f);


	blok.create();
	moneta.create();

	//okno
	while (window.isOpen())
	{
		Event event;
		//zdarzenia
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
				{
					wybrana_opcja_pauza = 1;
				}

				if (event.key.code == Keyboard::F1)
				{
					stop = stop + 1;
				}
				
				if (event.key.code == Keyboard::L)
				{
					moneta.wczytaj();
					load = 1;
					zegarload.restart();				
				}

				if (event.key.code == Keyboard::Z)
				{
					moneta.zapisz();
					save = 1;
					zegarsave.restart();
				}
				
				if (event.key.code == Keyboard::Up)
				{
					menu.MoveUp();
					menusmierc.MoveUp();
					menusmierc2.MoveUp();
				}

				if (event.key.code == Keyboard::Left)
				{
					menupauza.MoveLeft();
				}

				if (event.key.code == Keyboard::Right)
				{
					menupauza.MoveRight();
				}

				if (event.key.code == Keyboard::Down)
				{
					menu.MoveDown();
					menusmierc.MoveDown();
					menusmierc2.MoveDown();
				}

				if (wybrana_opcja == 0)
				{
					if (event.key.code == Keyboard::Enter && menu.getSelectedItem() == 0)
					{
						wybrana_opcja = 1;
					}

					if (event.key.code == Keyboard::Enter && menu.getSelectedItem() == 1)
					{
						window.close();
					}
				}

				if (wybrana_opcja_pauza == 1)
				{
					if (event.key.code == Keyboard::Enter && menupauza.getSelectedItemK() == 0)
					{
						wybrana_opcja_pauza = 2;
						window.close();
					}

					if (event.key.code == Keyboard::Enter && menupauza.getSelectedItemK() == 1)
					{
						wybrana_opcja_pauza = 2;
					}
				}			
					if (event.key.code == Keyboard::Enter && menusmierc.getSelectedItemS() == 0)
					{
						wybrana_opcja_smierc = wybrana_opcja_smierc + 1;
						if (wybrana_opcja_smierc == 3)
						reset.restart();
					}

					if (event.key.code == Keyboard::Enter && menusmierc.getSelectedItemS() == 1) 
					{
						window.close();
					}

				if (wybrana_opcja_smierc_2 == 1)
				{
					if (event.key.code == Keyboard::Enter && menusmierc2.getSelectedItemS2() == 0)
					{
						wybrana_opcja_smierc_2 == 2;
						window.close();
					}
				}

			}
		}

		if (wybrana_opcja == 0)
		{
			window.draw(tlo);
			window.draw(ludzikmenu);
			window.draw(blockmenu);

			menu.draw(window);

			nazwy.drawsj(window);
			nazwy.drawwczytaj(window);
			if (load == 1)
			{
				if (zegarload.getElapsedTime().asMilliseconds() < 5000.0f)
				{
					nazwy.drawwczytano(window);
				}
			}
		}
		if (wybrana_opcja == 1)
		{
			window.draw(tlo);

			if (zegar5.getElapsedTime().asMilliseconds() < 6000.0f)
			{
				podest.draw(window);
			}

			if (wybrana_opcja_pauza != 1) 
			{
				gracz.draw(window);
				gracz.ruch();
				gracz.animacjaludzika();
				gracz.pozycja();
				gracz.smierc();

				moneta.draw(window);

				blok.draw(window);
				blok.rollup(gracz);
				blok.kolizja(gracz);


				if (zegar.getElapsedTime().asMilliseconds() > 5.f)
				{
					bot1.kolizja(gracz);
					bot1.animuj();
					bot2.kolizja(gracz);
					bot2.animuj();
					zegar.restart();
				}

				window.draw(bot1.getBot());
				window.draw(bot2.getBot());

				moneta.drawnapis(window);
				moneta.drawpunkty(window);
				moneta.rollup(gracz);
				moneta.animacjamonety();
				moneta.dodaj_monety_kolizja(gracz);

				timer.count(gracz);
				timer.drawnapis(window);
				timer.drawczas(window);

				nazwy.drawzapisz(window);
				nazwy.drawhelpnapis(window);

				if (save == 1)
				{
					if (zegarsave.getElapsedTime().asMilliseconds() < 5000.0f)
					{
						nazwy.drawzapisano(window);
					}
				}
				if (stop % 2 == 1)
				{
					nazwy.drawhelp(window);
				}


				if (wybrana_opcja_smierc < 3)
				{
					menusmierc.draw(window, gracz);
					gracz.drawumarles(window);
					timer.drawnapissmierc(window, gracz);
					timer.drawczassmierc(window, gracz);
					moneta.drawpunktysmierc(window, gracz);
					moneta.drawnapissmierc(window, gracz);

					gracz.drawserce(window);
					gracz.drawserce2(window);
				}
				else
				{
					wybrana_opcja_smierc_2 = 1;
					gracz.wroc();
					gracz.drawserce(window);

					if ((wybrana_opcja_smierc >= 3) && (reset.getElapsedTime().asSeconds() > 2.0f))
					{
						menusmierc2.draw(window, gracz);
						gracz.drawumarles(window);
						timer.drawnapissmierc(window, gracz);
						timer.drawczassmierc(window, gracz);
						moneta.drawpunktysmierc(window, gracz);
						moneta.drawnapissmierc(window, gracz);
					}
				}
			}

			if (wybrana_opcja_pauza == 1)
			{
				gracz.draw(window);
				gracz.animacjaludzika();
				gracz.pozycja();
				gracz.smierc();

				moneta.draw(window);

				blok.draw(window);
				blok.kolizja(gracz);

				window.draw(bot1.getBot());
				window.draw(bot2.getBot());

				moneta.drawnapis(window);
				moneta.drawpunkty(window);
				moneta.animacjamonety();
				moneta.dodaj_monety_kolizja(gracz);

				timer.drawnapis(window);
				timer.drawczas(window);

				nazwy.drawpauza(window);
				nazwy.drawleavegame(window);
				nazwy.drawzapisz(window);
				nazwy.drawhelpnapis(window);

				if (save == 1)
				{
					if (zegarsave.getElapsedTime().asMilliseconds() < 5000.0f)
					{
						nazwy.drawzapisano(window);
					}
				}

				menupauza.draw(window);

				gracz.drawserce(window);
				gracz.drawserce2(window);
			}
		}
		window.display();
	}
	return 0;
}
