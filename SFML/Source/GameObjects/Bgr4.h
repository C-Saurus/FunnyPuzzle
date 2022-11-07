#pragma once
#include "../GameManager/ResourceManager.h"

class Bgr4 {
public:
	Bgr4();
	~Bgr4();

	void Init();
	void Render(sf::RenderWindow* window);

private:
	sf::Sprite bgr;
};