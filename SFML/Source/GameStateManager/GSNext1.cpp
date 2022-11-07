#include "GSNext1.h"
GSNext1::GSNext1()
{
}

GSNext1::~GSNext1()
{
}

void GSNext1::Exit()
{
}

void GSNext1::Pause()
{
}

void GSNext1::Resume()
{
}

void GSNext1::Init()
{
	GameButton* button;
	//menu Button
	button = new GameButton();
	button->Init("menu");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(150, 150));
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8 - 150);
	button->setOnClick([]() {
		DATA->playSound("btn");
		DATA->getSound("btn")->setVolume(50);
		GSM->PopState();
		GSM->PopState();
		GSM->PopState();
		GSM->ChangeState(StateTypes::MENU);
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
		});
	m_ListBtn.push_back(button);

	//next Button
	button = new GameButton();
	button->Init("next");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(150, 150));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8 - 150);
	button->setOnClick([]() {
		DATA->playSound("btn");
		DATA->getSound("btn")->setVolume(50);
		GSM->PopState();
		GSM->PopState();
		GSM->ChangeState(StateTypes::PLAY2);
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
		});
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("bgr/background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	m_Title.setString("Congratulation");
	m_Title.setFillColor(sf::Color::Green);
	m_Title.setFont(*DATA->getFont("yoshisst"));
	m_Title.setPosition(screenWidth / 2 - 100, screenHeight / 5);

	DATA->playSound("next");
	DATA->getSound("next")->setVolume(30);
}

void GSNext1::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSNext1::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
	window->draw(m_bestScore);
	window->draw(m_currentScore);
}