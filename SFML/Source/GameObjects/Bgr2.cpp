#include "Bgr2.h"
Bgr2::Bgr2()
{
}

Bgr2::~Bgr2()
{
}

void Bgr2::Init()
{
	sf::Texture* texture = DATA->getTexture("bgr/bgr2");
	bgr.setTexture(*texture);
	bgr.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	bgr.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);
}

void Bgr2::Render(sf::RenderWindow* window)
{
	window->draw(bgr);
}
