#pragma once
#include "../GameManager/ResourceManager.h"

class Bgr3 {
public:
	Bgr3();
	~Bgr3();

	void Init();
	void Render(sf::RenderWindow* window);

private:
	sf::Sprite bgr;
};