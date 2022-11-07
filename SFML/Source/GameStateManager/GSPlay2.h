#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Object2.h"
#include "../GameObjects/Bgr2.h"

class GSPlay2 : public GameStateBase {
public:
	GSPlay2();
	virtual ~GSPlay2();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	Object2* m_object = new Object2();
	Bgr2 m_bgr;
	bool isPlaying;
	int m_currentScore;
	float m_currentTime;
	sf::Text m_Score;
	sf::Text m_title;
	sf::Text level;
	sf::Text m_star;
	sf::RectangleShape star;
};
