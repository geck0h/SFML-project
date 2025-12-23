#pragma once

#include "SFML/Graphics.hpp"

class HittableObject
{
public:
	HittableObject(const char* texPath);

	~HittableObject();

	void RelocateSprite();

	bool IsCollided(const sf::Sprite& sprite);

	void MoveObject(const float& speed);

	void ResetObject();

	void DrawObject(sf::RenderWindow& window);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite1, m_sprite2;
	float m_acceleration;
};

