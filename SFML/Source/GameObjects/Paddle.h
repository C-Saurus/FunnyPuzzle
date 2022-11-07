#pragma once
#include "../GameManager/Singleton.h" 
#include "../GameManager/ResourceManager.h"

class Paddle :public CSingleton<Paddle> {
public:
	Paddle();
	~Paddle();

	float getSpeed();
	void Update();

public:
	float paddleSpeed = 150.0f;
	sf::Text t;
};