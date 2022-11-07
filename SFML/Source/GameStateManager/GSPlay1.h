#pragma once
#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Object1.h"
#include "../GameObjects/Bgr1.h"

class GSPlay1 : public GameStateBase {
public:
	GSPlay1();
	virtual ~GSPlay1();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	Object1* m_object = new Object1();
	Bgr1 m_bgr;
	bool isPlaying;
	int m_currentScore;
	float m_currentTime;
	sf::Text m_Score;
	sf::Text m_title;
	sf::Text level;
	sf::Text m_star;
	sf::RectangleShape star;
};