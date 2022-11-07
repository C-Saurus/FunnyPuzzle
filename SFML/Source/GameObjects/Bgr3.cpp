#include "Bgr3.h"
Bgr3::Bgr3()
{
}

Bgr3::~Bgr3()
{
}

void Bgr3::Init()
{
	sf::Texture* texture = DATA->getTexture("bgr/bgr3");
	bgr.setTexture(*texture);
	bgr.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	bgr.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);
}

void Bgr3::Render(sf::RenderWindow* window)
{
	window->draw(bgr);
}
