#pragma once
#include "../GameManager/ResourceManager.h"
#include "Paddle.h"
class Object4 : public Paddle {
public:
	Object4();
	~Object4();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Start();
	bool isP();
	bool isW();
	void upSpeed();
	int cStar();

public:
	sf::RectangleShape movePaddle;
	sf::RectangleShape paddle1;
	sf::RectangleShape paddle2;
	sf::RectangleShape paddle3;
	sf::RectangleShape autoPaddle1;
	sf::RectangleShape autoPaddle2;
	sf::RectangleShape autoPaddle3;

	sf::CircleShape ball;
	float angleBall = 0.f;
	float ballSpeed;
	float aPSpeed1, aPSpeed2, aPSpeed3;

	sf::RectangleShape target1;
	sf::RectangleShape target2;
	sf::RectangleShape target3;

	bool checkW1 = true;
	bool checkW2 = true;
	bool checkW3 = true;

	int botTarget1 = screenHeight / 2;
	int botTarget2 = screenWidth / 2;
	float botPeriod = 0.2f;
	float botTimer = 0.f;
};