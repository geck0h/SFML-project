#pragma once

#include "SFML/Graphics.hpp"

#include "mapConstants.h"

class Character
{
public:
	Character(const char* texPath);

	~Character();

	inline const sf::Sprite GetSprite()
	{
		return m_sprite;
	}

	void MoveSprite(const sf::Event::KeyPressed& key);

	void ResetCharacter();

	void DrawCharacter(sf::RenderWindow& window);

private:
	unsigned int m_curLane;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

