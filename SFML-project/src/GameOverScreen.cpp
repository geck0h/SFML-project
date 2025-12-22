#include "GameOverScreen.h"

#include "ScoreManager.h"

#include <string>


GameOverScreen::GameOverScreen(const sf::RenderWindow& window)
	: m_window({ window.getSize().x * 2.0f / 4.0f,
				 window.getSize().y * 2.0f / 4.0f }),
	  m_button({ window.getSize().x * 0.4f / 4.0f,
				 window.getSize().y * 0.2f / 4.0f }),
	  m_gameOverFont("res/fonts/Freedom-10eM.ttf"), m_title(m_gameOverFont), 
	  m_infoFont("res/fonts/Nasa21-l23X.ttf"), m_curScore(m_infoFont), m_highScore(m_infoFont), m_restart(m_infoFont)
{
	m_window.setPosition({ static_cast<float>(window.getSize().x) / 4.0f,
						   static_cast<float>(window.getSize().y) / 4.0f }
	);
	m_window.setFillColor({ 15, 10, 10, 230 });
	m_window.setOutlineColor({ 20, 15, 5, 230 });
	m_window.setOutlineThickness(5.0f);

	m_button.setPosition({ m_window.getSize().x - m_button.getSize().x / 2.0f,
						   m_window.getSize().y + m_button.getSize().y * 2.0f }
	);
	m_button.setFillColor({ 100, 0, 63, 240 });

	m_title.setString("  GAME OVER");
	m_title.setCharacterSize(48);
	m_title.setPosition({ static_cast<float>(m_window.getPosition().x),
						  static_cast<float>(m_window.getPosition().y) }
	);
	m_title.setFillColor({ 255, 144, 144, 255 });

	m_curScore.setString(" Current score is ");
	m_curScore.setCharacterSize(25);
	m_curScore.setPosition({ static_cast<float>(m_window.getPosition().x),
							 static_cast<float>(m_window.getPosition().y + m_title.getGlobalBounds().size.y * 4.0f) }
	);

	m_highScore.setString(" High score is ");
	m_highScore.setCharacterSize(25);
	m_highScore.setPosition({ static_cast<float>(m_window.getPosition().x),
							  static_cast<float>(m_window.getPosition().y + m_title.getGlobalBounds().size.y * 6.0f) }
	);

	m_restart.setString("Restart");
	m_restart.setCharacterSize(28);
	m_restart.setPosition({ m_button.getPosition().x, m_button.getPosition().y });
}

void GameOverScreen::UpdateScore(ScoreManager& scoreManager)
{
	scoreManager.SetCurScore();
	m_curScore.setString(" Current score is " + std::to_string(scoreManager.GetCurScore()) + "s");
	m_highScore.setString(" High score is " + std::to_string(scoreManager.GetHighScore()) + "s");
}

bool GameOverScreen::PressRestart(const int& x, const int& y)
{
	if (m_button.getGlobalBounds().contains({ static_cast<float>(x), static_cast<float>(y) }))
	{
		return true;
	}
	return false;
}

bool GameOverScreen::CheckPress(const sf::Vector2f& pos)
{
	if (m_button.getGlobalBounds().contains(pos))
	{
		return true;
	}
	return false;
}

void GameOverScreen::DrawWindow(sf::RenderWindow& window)
{
	window.draw(m_window);
	window.draw(m_button);
	window.draw(m_title);
	window.draw(m_curScore);
	window.draw(m_highScore);
	window.draw(m_restart);
}

GameOverScreen::~GameOverScreen()
{

}