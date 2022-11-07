#include "GSAbout.h"
GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("back");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(150, 150));
	button->setPosition(screenWidth / 10, screenHeight / 8);
	button->setOnClick([]() {
		GSM->PopState();
		DATA->playSound("btn");
		DATA->getSound("btn")->setVolume(50);
	});
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("bgr/bgr");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("ABOUT");
	m_Title.setFont(*DATA->getFont("Nunito-ExtraBold"));
	m_Title.setFillColor(sf::Color(255, 193, 193));
	m_Title.setPosition(screenWidth / 2 - 90, screenHeight / 5);

	m_text.setString("Press Left to move the paddle to the left\nPress Right to move the paddle to the right\nMove the ball to 3 targets to win points\nWatch out for obstacles\nTry to get all target to win the level\nand go to the next level\nYou will lose the ball that falls out.");
	m_text.setFont(*DATA->getFont("ARCADE"));
	m_text.setFillColor(sf::Color::Magenta);
	m_text.setPosition(screenWidth / 2 - 300, screenHeight / 5 + 100);
}

void GSAbout::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSAbout::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
	window->draw(m_text);
}
