#include "GSSettings.h"
GSSettings::GSSettings()
{
}

GSSettings::~GSSettings()
{
}

void GSSettings::Exit()
{
}

void GSSettings::Pause()
{
}

void GSSettings::Resume()
{
}

void GSSettings::Init()
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
		DATA->getSound("btn")->setVolume(30);
	});
	m_ListBtn.push_back(button);

	//turn on music
	button = new GameButton();
	button->Init("on");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->setAllowSound(true);
		DATA->getMusic("menu")->play();
		DATA->playSound("btn");
		DATA->getSound("btn")->setVolume(50);
	});
	m_ListBtn.push_back(button);

	//turn off music
	button = new GameButton();
	button->Init("off");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->getMusic("menu")->stop();
		DATA->setAllowSound(false); 
	});
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("bgr/bgr");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("SETTING MUSIC");
	m_Title.setFont(*DATA->getFont("Nunito-ExtraBold"));
	m_Title.setFillColor(sf::Color(255, 193, 193));
	m_Title.setPosition(screenWidth / 2 - 90, screenHeight / 5);
}

void GSSettings::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSSettings::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_Title);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}
