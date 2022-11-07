#pragma once
#include "GameStateBase.h"
#include "GameStateMachine.h"
class GSIntro : public GameStateBase {
public:
	GSIntro();
	virtual ~GSIntro();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Logo;
	float m_currentTime;
	sf::Text m_text;
	sf::Text text;
};