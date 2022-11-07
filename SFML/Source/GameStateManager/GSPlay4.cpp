#include "GSPlay4.h"

GSPlay4::GSPlay4()
{
	m_currentScore = 0;
	m_currentTime = 1.f;
	isPlaying = false;
}

GSPlay4::~GSPlay4()
{
}

void GSPlay4::Exit()
{
}

void GSPlay4::Pause()
{
}

void GSPlay4::Resume()
{
}

void GSPlay4::Init()
{
	m_object->Init();
	m_bgr.Init();

	level.setFont(*DATA->getFont("Nunito-ExtraBold"));
	level.setString("Level: 4");
	level.setFillColor(sf::Color(255, 187, 255));
	level.setPosition(10, 10);

	star.setTexture(DATA->getTexture("starwin"));
	star.setSize(targetSize);
	star.setOrigin(targetSize);
	star.setOutlineColor(sf::Color::Yellow);
	star.setPosition(screenWidth - 10, 50);


	m_star.setString(std::to_string(ScoreManager::GetInstance()->getHighScore()[0]));
	m_star.setFont(*DATA->getFont("Nunito-ExtraBold"));
	m_star.setFillColor(sf::Color::Yellow);
	m_star.setPosition(screenWidth - 12 - targetSize.x, 50);

	DATA->playMusic("play");
	DATA->getMusic("play")->setLoop(true);
	DATA->getMusic("play")->setVolume(30);
}

void GSPlay4::Update(float deltaTime)
{
	m_title.setString("Press Space to start");
	m_title.setFont(*DATA->getFont("ARCADE"));
	m_title.setFillColor(sf::Color::Green);
	m_title.setCharacterSize(50);
	m_title.setPosition(screenWidth / 2 - 200, screenHeight / 2 - 100);
	if (isPlaying == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		m_object->Start();
		isPlaying = true;
	}

	if (isPlaying) {
		m_object->Update(deltaTime);
		m_currentTime += deltaTime;
		if ((int)m_currentTime % 40 == 0) {
			m_object->upSpeed();
			m_currentTime = 1.0f;
		}
		if (m_object->isP() == false) {
			isPlaying = false;
			m_currentScore = m_object->cStar();
			ScoreManager::GetInstance()->setCurrentScore(m_currentScore);
			GSM->ChangeState(StateTypes::END);
			DATA->getMusic("play")->stop();
		}
	}
	if (m_object->isW() == true) {
		isPlaying = false;
		m_currentScore = m_object->cStar();
		ScoreManager::GetInstance()->setCurrentScore(m_currentScore);
		GSM->ChangeState(StateTypes::NEXT);
		DATA->getMusic("play")->stop();
	}
}

void GSPlay4::Render(sf::RenderWindow* window)
{
	m_bgr.Render(window);
	m_object->Render(window);
	window->draw(m_star);
	window->draw(star);
	window->draw(level);
	if (isPlaying == false) window->draw(m_title);
}