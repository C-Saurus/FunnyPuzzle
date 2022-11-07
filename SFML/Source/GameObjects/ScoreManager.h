#pragma once
#include "../GameManager/Singleton.h"

class ScoreManager :public CSingleton<ScoreManager>{
public:
	ScoreManager();
	void setCurrentScore(int s);
	int getCurrentScore();

	void UpdateHighScore();
	void Update(int price);

	int getBestScore();

	void readFile();
	void writeFile();

	int* getHighScore();

	void printScores();
private:
	int m_currentScore;
	int m_HighScore[1];
};