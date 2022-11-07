#include "Bgr4.h"
Bgr4::Bgr4()
{
}

Bgr4::~Bgr4()
{
}

void Bgr4::Init()
{
	sf::Texture* texture = DATA->getTexture("bgr/bgr4");
	bgr.setTexture(*texture);
	bgr.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	bgr.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);
}

void Bgr4::Render(sf::RenderWindow* window)
{
	window->draw(bgr);
}
