#include "Object4.h"

Object4::Object4()
{
	ballSpeed = 200.0f;
	aPSpeed1 = 150.0f;
	aPSpeed2 = 150.0f;
	aPSpeed3 = 200.0f;
}

Object4::~Object4()
{
}

void Object4::Init()
{
	//ball
	ball.setRadius(ballRadius);
	ball.setFillColor(sf::Color(131, 139, 131));
	ball.setOutlineColor(sf::Color::Black);
	ball.setPosition(screenWidth / 2, screenHeight / 2 + 180);
	//paddle

	movePaddle.setTexture(DATA->getTexture("paddle/paddle"));
	movePaddle.setOrigin(paddleSize);
	movePaddle.setSize(paddleSize);
	movePaddle.setPosition((screenWidth / 2) + 55, screenHeight);

	
	paddle1.setOrigin(b_paddleSize);
	paddle1.setSize(b_paddleSize);
	paddle1.setPosition((screenWidth / 2) - screenWidth / 4 + 20, screenHeight - 350);
	paddle1.setOutlineColor(sf::Color(72, 209, 204));
	paddle1.setFillColor(sf::Color(199, 21, 133));
	
	paddle2.setOrigin(a_paddleSize);
	paddle2.setSize(a_paddleSize);
	paddle2.setPosition((screenWidth / 2) + 50, screenHeight - 350);
	paddle2.setOutlineColor(sf::Color(72, 209, 204));
	paddle2.setFillColor(sf::Color(199, 21, 133));
	
	paddle3.setOrigin(b_paddleSize);
	paddle3.setSize(b_paddleSize);
	paddle3.setPosition((screenWidth / 2) + screenWidth / 4 - 20, screenHeight - 350);
	paddle3.setOutlineColor(sf::Color(72, 209, 204));
	paddle3.setFillColor(sf::Color(199, 21, 133));

	autoPaddle1.setOrigin(a_paddleSize);
	autoPaddle1.setSize(a_paddleSize);
	autoPaddle1.setPosition((screenWidth / 2) + 50, screenHeight - 200);
	autoPaddle1.setOutlineColor(sf::Color(72, 209, 204));
	autoPaddle1.setFillColor(sf::Color(199, 21, 133));

	autoPaddle2.setOrigin(a_paddleSize);
	autoPaddle2.setSize(a_paddleSize);
	autoPaddle2.setPosition((screenWidth / 2) + 50, screenHeight - 250);
	autoPaddle2.setOutlineColor(sf::Color(72, 209, 204));
	autoPaddle2.setFillColor(sf::Color(199, 21, 133));

	autoPaddle3.setOrigin(a_paddleSize);
	autoPaddle3.setSize(a_paddleSize);
	autoPaddle3.setPosition((screenWidth / 2) + 50, screenHeight - 300);
	autoPaddle3.setOutlineColor(sf::Color(72, 209, 204));
	autoPaddle3.setFillColor(sf::Color(199, 21, 133));

	//target
	target1.setTexture(DATA->getTexture("item/target4"));
	target1.setSize(targetSize);
	target1.setOrigin(targetSize);
	target1.setOutlineColor(sf::Color::Yellow);
	target1.setPosition(screenHeight / 2 + 200 + screenHeight / 4, screenWidth / 2 - 300);

	target2.setTexture(DATA->getTexture("item/target4"));
	target2.setSize(targetSize);
	target2.setOrigin(targetSize);
	target2.setOutlineColor(sf::Color::Yellow);
	target2.setPosition(screenHeight / 2 + 200, screenWidth / 2 - 300);

	target3.setTexture(DATA->getTexture("item/target4"));
	target3.setSize(targetSize);
	target3.setOrigin(targetSize);
	target3.setOutlineColor(sf::Color::Yellow);
	target3.setPosition(screenHeight / 2 + 200 - screenHeight / 4, screenWidth / 2 - 300);
}

void Object4::Update(float deltaTime)
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

	//bot
	// autoMovingPaddle
	sf::Vector2f pos1 = autoPaddle1.getPosition();
	sf::Vector2f pos2 = autoPaddle2.getPosition();
	sf::Vector2f pos3 = autoPaddle3.getPosition();
	autoPaddle1.move(aPSpeed1 * deltaTime, 0);
	autoPaddle2.move(-aPSpeed2 * deltaTime, 0);
	autoPaddle3.move(aPSpeed3 * deltaTime, 0);

	if (pos1.x + (aPSpeed1 * deltaTime) >= screenWidth) {
		aPSpeed1 = -aPSpeed1;
	}
	else if (pos1.x - a_paddleSize.x + (aPSpeed1 * deltaTime) <= 0) {
		aPSpeed1 = -aPSpeed1;
	}

	if (pos2.x - (aPSpeed2 * deltaTime) >= screenWidth) {
		aPSpeed2 = -aPSpeed2;
	}
	else if (pos2.x - a_paddleSize.x - (aPSpeed2 * deltaTime) <= 0) {
		aPSpeed2 = -aPSpeed2;
	}

	if (pos3.x + a_paddleSize.x + (aPSpeed3 * deltaTime) >= screenWidth) {
		aPSpeed3 = -aPSpeed3;
	}
	else if (pos3.x - 2 * a_paddleSize.x + (aPSpeed3 * deltaTime) <= 0) {
		aPSpeed3 = -aPSpeed3;
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

	if (ball.getGlobalBounds().intersects(autoPaddle2.getGlobalBounds()))
	{

		if (ball.getPosition().x > autoPaddle2.getPosition().x && autoPaddle2.getPosition().x > screenWidth / 2) {
			angleBall = 90.f - angleBall;
		}
		else if (ball.getPosition().x < autoPaddle2.getPosition().x && autoPaddle2.getPosition().x < screenWidth / 2) {
			angleBall = 90.f + angleBall;
		}
		else angleBall = 180.f - angleBall;
		DATA->playSound("ball");
		DATA->getSound("ball")->setVolume(20);
	}

	if (ball.getGlobalBounds().intersects(autoPaddle1.getGlobalBounds()))
	{

		if (ball.getPosition().x > autoPaddle1.getPosition().x && autoPaddle1.getPosition().x > screenWidth / 2) {
			angleBall = 90.f - angleBall;
		}
		else if (ball.getPosition().x < autoPaddle1.getPosition().x && autoPaddle1.getPosition().x < screenWidth / 2) {
			angleBall = 90.f + angleBall;
		}
		else angleBall = 180.f - angleBall;
		DATA->playSound("ball");
		DATA->getSound("ball")->setVolume(20);
	}

	if (ball.getGlobalBounds().intersects(autoPaddle3.getGlobalBounds()))
	{

		if (ball.getPosition().x > autoPaddle3.getPosition().x && autoPaddle3.getPosition().x > screenWidth / 2) {
			angleBall = 90.f - angleBall;
		}
		else if (ball.getPosition().x < autoPaddle3.getPosition().x && autoPaddle3.getPosition().x < screenWidth / 2) {
			angleBall = 90.f + angleBall;
		}
		else angleBall = 180.f - angleBall;
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

void Object4::Render(sf::RenderWindow* window)
{
	window->draw(movePaddle);
	window->draw(autoPaddle1);
	window->draw(autoPaddle2);
	window->draw(autoPaddle3);
	window->draw(paddle1);
	window->draw(paddle2);
	window->draw(paddle3);
	window->draw(ball);
	if (checkW1 != false) window->draw(target1);
	if (checkW2 != false) window->draw(target2);
	if (checkW3 != false) window->draw(target3);
}

void Object4::Start()
{
	do {
		angleBall = 270;
		angleBall = rand() % 360;
	} while (angleBall > 225 || angleBall < 135);
}

bool Object4::isP()
{
	if (ball.getPosition().y + paddleSize.y / 2 >= screenHeight) {
		return false;
	}
}

bool Object4::isW()
{
	if (!checkW1 && !checkW2 && !checkW3) return true;
	return false;
}

void Object4::upSpeed()
{
	ballSpeed += 50.0f;
}

int Object4::cStar()
{
	int count = 0;
	if (!checkW1) count++;
	if (!checkW2) count++;
	if (!checkW3) count++;
	return count;
}