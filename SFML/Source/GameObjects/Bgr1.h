#pragma once
#include "../GameManager/ResourceManager.h"

class Bgr1 {
public:
	Bgr1();
	~Bgr1();

	void Init();
	void Render(sf::RenderWindow* window);

private:
	sf::Sprite bgr;
};