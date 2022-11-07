#include "Object2.h"

Object2::Object2()
{
	ballSpeed = 200.0f;

}

Object2::~Object2()
{
}

void Object2::Init()
{
	//ball
	ball.setRadius(ballRadius);
	ball.setFillColor(sf::Color::Yellow);
	ball.setOutlineColor(sf::Color::Black);
	ball.setPosition(screenWidth / 2, screenHeight / 2 + 180);
	//paddle

	movePaddle.setTexture(DATA->getTexture("paddle/paddle0"));
	movePaddle.setOrigin(paddleSize);
	movePaddle.setSize(paddleSize);
	movePaddle.setPosition((screenWidth / 2) + 55, screenHeight);
	//	movePaddle.setOutlineColor(sf::Color(0, 0, 0));
	//	movePaddle.setFillColor(sf::Color::Green);

	paddle1.setTexture(DATA->getTexture("paddle/auto02"));
	paddle1.setOrigin(b_paddleSize);
	paddle1.setSize(b_paddleSize);
	paddle1.setPosition((screenWidth / 2) + 50 - screenWidth / 4, screenHeight - 300);

	paddle2.setTexture(DATA->getTexture("paddle/auto2"));
	paddle2.setOrigin(c_paddleSize);
	paddle2.setSize(c_paddleSize);
	paddle2.setPosition((screenWidth / 2) + 120, screenHeight - 300);

	paddle3.setTexture(DATA->getTexture("paddle/auto12"));
	paddle3.setOrigin(b_paddleSize);
	paddle3.setSize(b_paddleSize);
	paddle3.setPosition((screenWidth / 2) - 30 + screenWidth / 4, screenHeight - 300);

	//target
	target1.setTexture(DATA->getTexture("item/target2"));
	target1.setSize(targetSize);
	target1.setOrigin(targetSize);
	target1.setOutlineColor(sf::Color::Yellow);
	target1.setPosition(screenHeight / 2 + 200 + screenHeight / 4, screenWidth / 2 - 300);

	target2.setTexture(DATA->getTexture("item/target2"));
	target2.setSize(targetSize);
	target2.setOrigin(targetSize);
	target2.setOutlineColor(sf::Color::Yellow);
	target2.setPosition(screenHeight / 2 + 200, screenWidth / 2 - 300);

	target3.setTexture(DATA->getTexture("item/target2"));
	target3.setSize(targetSize);
	target3.setOrigin(targetSize);
	target3.setOutlineColor(sf::Color::Yellow);
	target3.setPosition(screenHeight / 2 + 200 - screenHeight / 4, screenWidth / 2 - 300);

}

void Object2::Update(float deltaTime)
{
	//paddle moving
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sf::Vector2f pos = movePaddle.getPosition();
		if (pos.x + paddleSpeed * deltaTime > screenWidth) movePaddle.setPosition(screenWidth, pos.y);
		else movePaddle.move(paddleSpeed * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sf::Vector2f pos = movePaddle.getPosition();
		if (pos.x - paddleSize.x - paddleSpeed * deltaTime < 0) movePaddle.setPosition(paddleSize.x, pos.y);
		else movePaddle.move(-paddleSpeed * deltaTime, 0);
	}

	//ball moving
	float factor = ballSpeed * deltaTime;
	ball.move(sin(angleBall * pi / 180) * factor, -cos(angleBall * pi / 180) * factor);


	//Check Collision Wall
	if (ball.getPosition().y <= 0) {
		angleBall = 180.f - angleBall;
		DATA->playSound("ball");
		DATA->getSound("ball")->setVolume(20);
	}

	if (ball.getPosition().x + 22 > screenWidth) {
		angleBall = 360.f - angleBall;
		DATA->playSound("ball");
		DATA->getSound("ball")->setVolume(20);
	}

	if (ball.getPosition().x <= 0) {
		angleBall = 360.f - angleBall;
		DATA->playSound("ball");
		DATA->getSound("ball")->setVolume(20);
	}

	//Check Collison with the movePaddle
	if (ball.getGlobalBounds().intersects(movePaddle.getGlobalBounds()))
	{
		if (ball.getPosition().x > movePaddle.getPosition().x && movePaddle.getPosition().x > screenWidth / 2) {
			angleBall = 90.f - angleBall;
		}
		else if (ball.getPosition().x < movePaddle.getPosition().x && movePaddle.getPosition().x < screenWidth / 2) {
			angleBall = 90.f + angleBall;
		}
		else angleBall = 180.f - angleBall;
		DATA->playSound("ball");
		DATA->getSound("ball")->setVolume(20);

	}

	//Check Collison with the autoPaddle

	if (ball.getGlobalBounds().intersects(paddle2.getGlobalBounds()))
	{

		if (ball.getPosition().x > paddle2.getPosition().x && paddle2.getPosition().x > screenWidth / 2) {
			angleBall = 90.f - angleBall;
		}
		else if (ball.getPosition().x < paddle2.getPosition().x && paddle2.getPosition().x < screenWidth / 2) {
			angleBall = 90.f + angleBall;
		}
		else angleBall = 180.f - angleBall;
		DATA->playSound("ball");
		DATA->getSound("ball")->setVolume(20);
	}

	if (ball.getGlobalBounds().intersects(paddle1.getGlobalBounds())) {
		angleBall = 360.f - angleBall;
		DATA->playSound("ball");
		DATA->getSound("ball")->setVolume(20);
	}

	if (ball.getGlobalBounds().intersects(paddle3.getGlobalBounds())) {
		angleBall = 360.f - angleBall;
		DATA->playSound("ball");
		DATA->getSound("ball")->setVolume(20);
	}

	if (ball.getGlobalBounds().intersects(target1.getGlobalBounds()) && checkW1) {
		checkW1 = false;
		DATA->playSound("star");
		DATA->getSound("star")->setVolume(20);
	}
	if (ball.getGlobalBounds().intersects(target2.getGlobalBounds()) && checkW2) {
		checkW2 = false;
		DATA->playSound("star");
		DATA->getSound("star")->setVolume(20);
	}
	if (ball.getGlobalBounds().intersects(target3.getGlobalBounds()) && checkW3) {
		checkW3 = false;
		DATA->playSound("star");
		DATA->getSound("star")->setVolume(20);
	}


}

void Object2::Render(sf::RenderWindow* window)
{
	window->draw(movePaddle);
	window->draw(paddle1);
	window->draw(paddle2);
	window->draw(paddle3);
	window->draw(ball);
	if (checkW1 != false) window->draw(target1);
	if (checkW2 != false) window->draw(target2);
	if (checkW3 != false) window->draw(target3);
}

void Object2::Start()
{
	do {
		angleBall = 270;
		angleBall = rand() % 360;
	} while (angleBall > 225 || angleBall < 135);
}

bool Object2::isP()
{
	if (ball.getPosition().y + paddleSize.y / 2 >= screenHeight) {
		return false;
	}
}

bool Object2::isW()
{
	if (!checkW1 && !checkW2 && !checkW3) return true;
	return false;
}

void Object2::upSpeed()
{
	ballSpeed += 50.0f;
}

int Object2::cStar()
{
	int count = 0;
	if (!checkW1) count++;
	if (!checkW2) count++;
	if (!checkW3) count++;
	return count;
}