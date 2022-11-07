#pragma once
#include "../GameManager/ResourceManager.h"

class Bgr2 {
public:
	Bgr2();
	~Bgr2();

	void Init();
	void Render(sf::RenderWindow* window);

private:
	sf::Sprite bgr;
};