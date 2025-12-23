#include "HittableObject.h"

#include "mapConstants.h"

#include <cstdlib>

static constexpr float s_spawnLocationY = -100.0f;

HittableObject::HittableObject(const char* texPath)
	: m_texture(texPath), m_sprite1(m_texture), m_sprite2(m_texture), m_acceleration(0.0f)
{
	m_sprite1.setScale({ 0.075f, 0.075f });
	m_sprite1.setPosition({ s_lanes[0].x - 90.0f, s_spawnLocationY });

	m_sprite2.setScale({ 0.075f, 0.075f });
	m_sprite2.setPosition({ s_lanes[2].x - 90.0f, s_spawnLocationY - 100.0f });
}

void HittableObject::RelocateSprite()
{
	if (m_sprite1.getPosition().y >= m_sprite1.getLocalBounds().size.y)
	{
		int switchedLane = rand() % 4;

		m_sprite1.setPosition({ s_lanes[switchedLane].x - 90.0f, s_spawnLocationY });

		m_acceleration += 20.0f;
	}
	if (m_sprite2.getPosition().y >= m_sprite2.getLocalBounds().size.y)
	{
		int switchedLane = rand() % 4;

		m_sprite2.setPosition({ s_lanes[switchedLane].x - 90.0f, s_spawnLocationY });
	}
}

bool HittableObject::IsCollided(const sf::Sprite& sprite)
{
	sf::FloatRect hitbox = sprite.getGlobalBounds();
	sf::FloatRect obstacle1 = m_sprite1.getGlobalBounds();
	sf::FloatRect obstacle2 = m_sprite2.getGlobalBounds();
	if (const std::optional intersection = hitbox.findIntersection(obstacle1))
	{
		return true;
	}
	if (const std::optional intersection = hitbox.findIntersection(obstacle2))
	{
		return true;
	}

	return false;
}

void HittableObject::MoveObject(const float& speed)
{
	m_sprite1.move({ 0.0f, speed });
	m_sprite2.move({ 0.0f, speed });
}

void HittableObject::ResetObject()
{
	m_sprite1.setPosition({ s_lanes[1].x - 90.0f, s_spawnLocationY });
	m_sprite2.setPosition({ s_lanes[3].x - 90.0f, s_spawnLocationY - 100.0f });
}

void HittableObject::DrawObject(sf::RenderWindow& window)
{
	window.draw(m_sprite1);
	window.draw(m_sprite2);
}

HittableObject::~HittableObject()
{
}