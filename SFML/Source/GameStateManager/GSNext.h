#pragma once
#include "GameStateBase.h"

class GSNext : public GameStateBase {
public:
	GSNext();
	virtual ~GSNext();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	sf::Sprite m_Background;
	std::list<GameButton*> m_ListBtn;
	sf::Text m_Title;
	sf::Text m_currentScore;
	sf::Text m_bestScore;
};
