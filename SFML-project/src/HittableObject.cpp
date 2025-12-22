#include "HittableObject.h"

#include "mapConstants.h"

#include <cstdlib>

static constexpr float s_spawnLocationY = -100.0f;

HittableObject::HittableObject(const char* texPath)
	: m_texture(texPath), m_sprite(m_texture), m_acceleration(0.0f)
{
	m_sprite.setScale({ 0.075f, 0.075f });
	m_sprite.setPosition({ s_lanes[0].x - 90.0f, s_spawnLocationY });
}

void HittableObject::RelocateSprite()
{
	if (m_sprite.getPosition().y >= m_sprite.getLocalBounds().size.y)
	{
		int switchedLane = rand() % 4;

		m_sprite.setPosition({ s_lanes[switchedLane].x - 90.0f, s_spawnLocationY });

		m_acceleration += 20.0f;
	}
}

bool HittableObject::IsCollided(const sf::Sprite& sprite)
{
	sf::FloatRect hitbox = sprite.getGlobalBounds();
	sf::FloatRect obstacle = m_sprite.getGlobalBounds();
	if (const std::optional intersection = hitbox.findIntersection(obstacle))
	{
		return true;
	}

	return false;
}

void HittableObject::MoveObject(const float& speed)
{
	m_sprite.move({ 0.0, speed });
}

void HittableObject::ResetObject()
{
	m_sprite.setPosition({ s_lanes[1].x - 90.0f, s_spawnLocationY });
}

void HittableObject::DrawObject(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

HittableObject::~HittableObject()
{
}