#include "Bgr.h"
Bgr::Bgr()
{
}

Bgr::~Bgr()
{
}

void Bgr::Init()
{
	sf::Texture* texture = DATA->getTexture("bgr/bgr0");
	bgr.setTexture(*texture);
	bgr.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	bgr.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);
}

void Bgr::Render(sf::RenderWindow* window)
{
	window->draw(bgr);
}
