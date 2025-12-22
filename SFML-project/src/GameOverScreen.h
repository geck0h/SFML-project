#pragma once

#include "ScoreManager.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class GameOverScreen
{
public:
	GameOverScreen(const sf::RenderWindow& window);

	~GameOverScreen();

	void UpdateScore(ScoreManager& scoreManager);
	
	bool PressRestart(const int& x, const int& y);

	bool CheckPress(const sf::Vector2f& pos);

	void DrawWindow(sf::RenderWindow& window);

private:
	sf::RectangleShape m_window;
	sf::RectangleShape m_button;
	sf::Font m_gameOverFont, m_infoFont;
	sf::Text m_title, m_highScore, m_curScore, m_restart;
};

