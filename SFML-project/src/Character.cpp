#include "Character.h"

#include "mapConstants.h"

Character::Character(const char* texPath)
	: m_curLane(0), m_texture(texPath), m_sprite(m_texture)
{
	m_sprite.setPosition(s_lanes[0]);
	m_sprite.scale({ 0.1f, 0.1f });
	m_sprite.rotate(sf::degrees(90.0f));
}

void Character::MoveSprite(const sf::Event::KeyPressed& key)
{
	if (key.scancode == sf::Keyboard::Scan::A && m_curLane > 0)				m_curLane -= 1;
	else if (key.scancode == sf::Keyboard::Scan::D && m_curLane < 3)		m_curLane += 1;

	m_sprite.setPosition(s_lanes[m_curLane]);
}

void Character::ResetCharacter()
{
	m_curLane = 0;
	m_sprite.setPosition(s_lanes[m_curLane]);
}

void Character::DrawCharacter(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

Character::~Character() 
{
}