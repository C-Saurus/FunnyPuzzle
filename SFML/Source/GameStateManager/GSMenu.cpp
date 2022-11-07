#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	GameButton* button;
	//PlayButton
	button = new GameButton();
	button->Init("play");
	button->setOnClick([]() {
		DATA->getMusic("menu")->stop();
		GSM->ChangeState(StateTypes::PLAY);
		DATA->playSound("btn");
		DATA->getSound("btn")->setVolume(50);
	});
	button->setPosition(screenWidth / 2, screenHeight / 2);
	button->setSize(sf::Vector2f(150, 150));
	button->setOrigin(button->getSize() / 2.f);
	m_ListBtn.push_back(button);

	//Exit Button
	button = new GameButton();
	button->Init("quit");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 6);
	button->setOnClick([]() {
		WConnect->getWindow()->close(); 
		DATA->playSound("btn");
		DATA->getSound("btn")->setVolume(50);
	});
	button->setSize(sf::Vector2f(150, 150));
	m_ListBtn.push_back(button);

	//Setting Button
	button = new GameButton();
	button->Init("settings");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 6);
	button->setOnClick([]() {
		GSM->ChangeState(StateTypes::SETTING); 
		DATA->playSound("btn");
		DATA->getSound("btn")->setVolume(50);
	});
	button->setSize(sf::Vector2f(150, 150));
	m_ListBtn.push_back(button);

	//About Button
	button = new GameButton();
	button->Init("about");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOnClick([]() {
		GSM->ChangeState(StateTypes::ABOUT); 
		DATA->playSound("btn");
		DATA->getSound("btn")->setVolume(50);
	});
	button->setSize(sf::Vector2f(150, 150));
	m_ListBtn.push_back(button);

	//HighScore Button
	button = new GameButton();
	button->Init("upgrade");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOnClick([]() {
		GSM->ChangeState(StateTypes::UPGRADE); 
		DATA->playSound("btn");
		DATA->getSound("btn")->setVolume(50);
	});
	button->setSize(sf::Vector2f(150, 150));
	m_ListBtn.push_back(button);


	//Background
	sf::Texture* texture = DATA->getTexture("bgr/background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Star
	star.setTexture(DATA->getTexture("starwin"));
	star.setSize(targetSize);
	star.setOrigin(targetSize);
	star.setOutlineColor(sf::Color::Yellow);
	star.setPosition(screenWidth - 10, 50);


	m_star.setString(std::to_string(ScoreManager::GetInstance()->getHighScore()[0]));
	m_star.setFont(*DATA->getFont("Nunito-ExtraBold"));
	m_star.setFillColor(sf::Color::Yellow);
	m_star.setPosition(screenWidth - 12 - targetSize.x, 50);

	m_text.setString("FUNNY PONGGG");
	m_text.setFont(*DATA->getFont("yoshisst"));
	m_text.setCharacterSize(50);
	m_text.setFillColor(sf::Color(255, 193, 193));
	m_text.setPosition(screenWidth / 2 - 60, screenHeight / 2 - 150);

	DATA->playMusic("menu");
	DATA->getMusic("menu")->setLoop(true);
	DATA->getMusic("menu")->setVolume(30);
}

void GSMenu::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(star);
	window->draw(m_star);
	window->draw(m_text);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}
