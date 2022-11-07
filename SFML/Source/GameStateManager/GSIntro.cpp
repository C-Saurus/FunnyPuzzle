#include "GSIntro.h"

GSIntro::GSIntro()
{
	m_currentTime = 0.f;
}

GSIntro::~GSIntro()
{
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	sf::Texture* texture = DATA->getTexture("Logo");
	m_Logo.setTexture(*texture);
	m_Logo.setPosition(screenWidth / 2, screenHeight / 2);
	m_Logo.setOrigin((sf::Vector2f)texture->getSize() / 2.f);

	m_text.setString("LMI9");
	m_text.setFont(*DATA->getFont("turok"));
	m_text.setCharacterSize(60);
	m_text.setFillColor(sf::Color(122, 139, 139));
	m_text.setPosition(screenWidth / 2 + 50, screenHeight/2 + 200);
	m_text.setOrigin((sf::Vector2f)texture->getSize() / 2.f);

	text.setString("ProPTIT");
	text.setFont(*DATA->getFont("turok"));
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setPosition(screenWidth / 2 + 50, screenHeight / 2 - 200);
	text.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	
	DATA->playSound("intro");
	DATA->getSound("intro")->setVolume(30);
}

void GSIntro::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= 4.5f) {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->draw(m_Logo);
	window->draw(m_text);
	window->draw(text);
}
