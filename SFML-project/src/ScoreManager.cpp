#include "ScoreManager.h"

ScoreManager::ScoreManager()
	: m_highScore(0.0f), m_curScore(0.0f), m_clock(), m_isSet(false)
{
	m_clock.restart();
}

float ScoreManager::GetHighScore()
{
	if (m_curScore > m_highScore)
	{
		m_highScore = m_curScore;
	}
	return m_highScore;
}

void ScoreManager::SetCurScore()
{
	if (!m_isSet) 
	{
		m_curScore = m_clock.reset().asSeconds();
	}
	m_isSet = true;
}

void ScoreManager::StartNewClock()
{
	m_isSet = false;
	m_clock.restart();
}

ScoreManager::~ScoreManager()
{
}