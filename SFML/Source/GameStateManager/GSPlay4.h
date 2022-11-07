#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Object4.h"
#include "../GameObjects/Bgr4.h"

class GSPlay4 : public GameStateBase {
public:
	GSPlay4();
	virtual ~GSPlay4();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	Object4* m_object = new Object4();
	Bgr4 m_bgr;
	bool isPlaying;
	int m_currentScore;
	float m_currentTime;
	sf::Text m_Score;
	sf::Text m_title;
	sf::Text level;
	sf::Text m_star;
	sf::RectangleShape star;
};
