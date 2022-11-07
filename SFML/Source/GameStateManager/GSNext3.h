#pragma once
#include "GameStateBase.h"

class GSNext3 : public GameStateBase {
public:
	GSNext3();
	virtual ~GSNext3();

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
