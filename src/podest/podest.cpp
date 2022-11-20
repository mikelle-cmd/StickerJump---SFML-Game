#include "podest.h"
#include <iostream>

using namespace std;
using namespace sf;

Podest::Podest()
{
	texture3.loadFromFile("podest.png");
	podest.setTexture(texture3);
	podest.setTextureRect(IntRect(10, 10, 800, 10));
	podest.setPosition(0, 590);
}
Podest::~Podest()
{
}

void Podest::draw(RenderWindow& window)
{
	window.draw(podest);
}


