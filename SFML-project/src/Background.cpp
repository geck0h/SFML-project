#include "Background.h"

#include "SFML/Window.hpp"

Background::Background(const char* texPath)
	: m_texture(texPath), m_backgroundSprite1(m_texture), m_backgroundSprite2(m_texture), m_roadSpeed(200.0f)
{	
	m_backgroundSprite1.setTexture(m_texture);
	m_backgroundSprite1.setPosition({ 0.0f, 0.0f });
	
	m_backgroundSprite2.setTexture(m_texture);
	m_backgroundSprite2.setPosition({ 0.0f, -m_backgroundSprite1.getLocalBounds().size.y });
}

void Background::MoveBackground(const float deltaTime)
{
	const float height = m_backgroundSprite1.getGlobalBounds().size.y;

	if (m_backgroundSprite1.getPosition().y >= height)
	{
		m_backgroundSprite1.setPosition({ 0.0f, m_backgroundSprite2.getPosition().y - height});
		m_roadSpeed += 20.0f;
	}
	if (m_backgroundSprite2.getPosition().y >= height)
	{
		m_backgroundSprite2.setPosition({ 0.0f, m_backgroundSprite1.getPosition().y - height});
		m_roadSpeed += 20.0f;
	}

	m_backgroundSprite1.move({ 0.0f, deltaTime * m_roadSpeed });
	m_backgroundSprite2.move({ 0.0f, deltaTime * m_roadSpeed }) ;
}

void Background::ResetBackground()
{
	m_backgroundSprite1.setPosition({ 0.0f, 0.0f });
	m_backgroundSprite2.setPosition({ 0.0f, -m_backgroundSprite1.getLocalBounds().size.y });
	
	m_roadSpeed = 200.0f;
}

void Background::DrawBackground(sf::RenderWindow& window)
{
	window.draw(m_backgroundSprite2);
	window.draw(m_backgroundSprite1);
}

Background::~Background()
{
}