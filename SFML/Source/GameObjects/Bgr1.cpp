#include "Bgr1.h"
Bgr1::Bgr1()
{
}

Bgr1::~Bgr1()
{
}

void Bgr1::Init()
{
	sf::Texture* texture = DATA->getTexture("bgr/bgr1");
	bgr.setTexture(*texture);
	bgr.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	bgr.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);
}

void Bgr1::Render(sf::RenderWindow* window)
{
	window->draw(bgr);
}
