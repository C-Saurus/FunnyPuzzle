#include "GSUpgrade.h"
GSUpgrade::GSUpgrade()
{
}

GSUpgrade::~GSUpgrade()
{
}

void GSUpgrade::Exit()
{
}

void GSUpgrade::Pause()
{
}

void GSUpgrade::Resume()
{
}

void GSUpgrade::Init()
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
	m_Title.setString("UPGRADE");
	m_Title.setFont(*DATA->getFont("Nunito-ExtraBold"));
	m_Title.setFillColor(sf::Color(255, 193, 193));
	m_Title.setPosition(screenWidth / 2 - 100, screenHeight / 5);

	star.setTexture(DATA->getTexture("starwin"));
	star.setSize(targetSize);
	star.setOrigin(targetSize);
	star.setOutlineColor(sf::Color::Yellow);
	star.setPosition(screenWidth - 10, 50);

	m_star.setString(std::to_string(ScoreManager::GetInstance()->getHighScore()[0]));
	m_star.setFont(*DATA->getFont("Nunito-ExtraBold"));
	m_star.setPosition(screenWidth - 12 - targetSize.x, 50);

	m_text.setString("You can use the stars earned here\nEvery 2 stars you can upgrade the speed of the paddle\nEach upgrade will be raised to 50f ");
	m_text.setFont(*DATA->getFont("ARCADE"));
	m_text.setFillColor(sf::Color::Magenta);
	m_text.setPosition(screenWidth / 2 - 350, screenHeight / 5 + 300);

	paddle.setTexture(DATA->getTexture("paddle/paddle"));
	paddle.setOrigin(paddleSize);
	paddle.setSize(paddleSize);
	paddle.setPosition(screenWidth - screenWidth / 8 - paddleSize.x, screenHeight / 2);

	button = new GameButton();
	button->Init("up");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth - screenWidth / 8, screenHeight / 2);
	button->setOnClick([]() {
		if (ScoreManager::GetInstance()->getHighScore()[0] >= 2) {
			ScoreManager::GetInstance()->Update(2);
			Paddle::GetInstance()->Update();
			DATA->playSound("up");
			DATA->getSound("up")->setVolume(30);
		}
	});
	m_ListBtn.push_back(button);
}

void GSUpgrade::Update(float deltaTime)
{

	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSUpgrade::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(paddle);
	window->draw(m_star);
	window->draw(star);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
	window->draw(m_text);
}
