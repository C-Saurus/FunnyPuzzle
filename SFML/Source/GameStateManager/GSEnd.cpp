#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
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
		GSM->ChangeState(StateTypes::MENU);
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
		});
	m_ListBtn.push_back(button);

	//replay Button
	button = new GameButton();
	button->Init("restart");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(150, 150));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8 - 150);
	button->setOnClick([]() {
		DATA->playSound("btn");
		DATA->getSound("btn")->setVolume(50);
		GSM->PopState();
		GSM->ChangeState(StateTypes::PLAY);
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
		});
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("bgr/background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("YOU LOST");
	m_Title.setFont(*DATA->getFont("Nunito-ExtraBold"));
	m_Title.setFillColor(sf::Color(255, 193, 193));
	m_Title.setPosition(screenWidth / 2 - 100, screenHeight / 5);

	//Best Score
	m_bestScore.setString("BEST SCORE: " + std::to_string(ScoreManager::GetInstance()->getBestScore()));
	m_bestScore.setFont(*DATA->getFont("Nunito-ExtraBold"));
	m_bestScore.setFillColor(sf::Color(238, 44, 44));
	m_bestScore.setPosition(screenWidth / 2 - 120, screenHeight / 2 - 120);

	//current Score
	m_currentScore.setString("YOUR SCORE: " + std::to_string(ScoreManager::GetInstance()->getCurrentScore()));
	m_currentScore.setFont(*DATA->getFont("Nunito-ExtraBold"));
	m_currentScore.setFillColor(sf::Color(238, 44, 44));
	m_currentScore.setPosition(screenWidth / 2 - 120, screenHeight / 2 - 70);

	DATA->playSound("end");
	DATA->getSound("end")->setVolume(30);
}

void GSEnd::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
	window->draw(m_bestScore);
	window->draw(m_currentScore);
}
