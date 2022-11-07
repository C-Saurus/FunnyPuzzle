#include "ScoreManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>

ScoreManager::ScoreManager()
{
	m_HighScore[0] = 0;
	m_currentScore = 0;
	printScores();
}

void ScoreManager::setCurrentScore(int s)
{
	m_currentScore = s;
}

int ScoreManager::getCurrentScore()
{
	return m_currentScore;
}

void ScoreManager::UpdateHighScore()
{
	int s = m_currentScore;
	m_HighScore[0] += s;
}

void ScoreManager::Update(int price)
{
	m_HighScore[0] -= price;
}

int ScoreManager::getBestScore()
{
	return m_HighScore[0];
}

void ScoreManager::readFile()
{
	std::fstream input;
	input.open("Score.data", std::ios::binary | std::ios::in);
	input.read((char*)m_HighScore, sizeof(m_HighScore));
	input.close();
}

void ScoreManager::writeFile()
{
	std::fstream output;
	output.open("Score.data", std::ios::binary | std::ios::out);
	output.write((char*)m_HighScore, sizeof(m_HighScore));
	output.close();
}

int* ScoreManager::getHighScore()
{
	return m_HighScore;
}

void ScoreManager::printScores()
{
	printf("%d", m_HighScore[0]);
}
