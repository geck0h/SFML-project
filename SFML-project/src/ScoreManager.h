#pragma once

#include "SFML/System.hpp"

class ScoreManager
{
public:
	ScoreManager();

	~ScoreManager();

	float GetHighScore();
	inline float GetCurScore()
	{
		return m_curScore;
	}

	void SetCurScore();
	
	void StartNewClock();

private:
	bool m_isSet;
	float m_highScore, m_curScore;
	sf::Clock m_clock;
};

