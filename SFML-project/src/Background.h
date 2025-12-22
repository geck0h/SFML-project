#pragma once

#include "SFML/Graphics.hpp"

class Background
{
public:
	Background(const char* texPath);

	~Background();

	void MoveBackground(const float speed);

	void DrawBackground(sf::RenderWindow& window);

	void ResetBackground();

	inline float GetRoadSpeed()
	{
		return m_roadSpeed;
	}

private:
	sf::Texture m_texture;
	sf::Sprite m_backgroundSprite1, m_backgroundSprite2;
	float m_roadSpeed;
};

