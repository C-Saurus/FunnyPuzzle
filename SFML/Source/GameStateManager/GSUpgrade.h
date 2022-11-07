#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Paddle.h"
class GSUpgrade : public GameStateBase{
public:
	GSUpgrade();
	virtual ~GSUpgrade();

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
	sf::Text m_star;
	sf::RectangleShape star;
	sf::RectangleShape paddle;
	sf::Text m_text;
};