#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Podest
{
public:
	Podest();
	~Podest();
	void draw(RenderWindow& window);

private:
	Texture texture3;
	Sprite podest;
	Clock zegar7;
};

