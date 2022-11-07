#pragma once
#include "../GameManager/ResourceManager.h"
#include "Paddle.h"
class Object : public Paddle {
public:
	Object();
	~Object();
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


	sf::CircleShape ball;
	float angleBall = 0.f;
	float ballSpeed;

	sf::RectangleShape target1;
	sf::RectangleShape target2;
	sf::RectangleShape target3;
	bool checkW1 = true;
	bool checkW2 = true;
	bool checkW3 = true;

};