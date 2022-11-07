#include "Paddle.h"
Paddle::Paddle()
{
}

Paddle::~Paddle()
{
}

float Paddle::getSpeed()
{
	return paddleSpeed;
}

void Paddle::Update()
{
	paddleSpeed += 50.0f;
}
