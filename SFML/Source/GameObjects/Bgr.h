#pragma once
#include "../GameManager/ResourceManager.h"

class Bgr {
public:
	Bgr();
	~Bgr();

	void Init();
	void Render(sf::RenderWindow* window);

private:
	sf::Sprite bgr;
};