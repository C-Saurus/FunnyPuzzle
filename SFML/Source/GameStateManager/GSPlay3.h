#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Object3.h"
#include "../GameObjects/Bgr3.h"

class GSPlay3 : public GameStateBase {
public:
	GSPlay3();
	virtual ~GSPlay3();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	Object3* m_object = new Object3();
	Bgr3 m_bgr;
	bool isPlaying;
	int m_currentScore;
	float m_currentTime;
	sf::Text m_Score;
	sf::Text m_title;
	sf::Text level;
	sf::Text m_star;
	sf::RectangleShape star;
};
