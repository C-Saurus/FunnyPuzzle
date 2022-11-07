#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Object.h"
#include "../GameObjects/Bgr.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	Object* m_object = new Object();
	Bgr m_bgr;
	bool isPlaying;
	int m_currentScore;
	float m_currentTime;
	sf::Text m_Score;
	sf::Text m_title;
	sf::Text level;
	sf::Text m_star;
	sf::RectangleShape star;
};
