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
	sf::Sprite m_sprite;
	float m_acceleration;
	// TODO: add so more rocks appear at once
};

