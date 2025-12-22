#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Character.h"
#include "Background.h"
#include "HittableObject.h"
#include "GameOverScreen.h"
#include "mapConstants.h"

#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 650 }), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
    bool windowPaused = false;

    Character character("res/textures/car.png");

    Background background("res/textures/road.png");
    
    HittableObject hittableObject("res/textures/rock.png");
    
    GameOverScreen gameOverScreen(window);

    ScoreManager scoreManager;

    sf::Clock clock;
    clock.start();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
                {
                    window.close();
                }
                else if ((keyPressed->scancode == sf::Keyboard::Scan::A || keyPressed->scancode == sf::Keyboard::Scan::D) && !windowPaused)
                {
                    character.MoveSprite(*keyPressed);
                }
            }
           
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (gameOverScreen.PressRestart(mouseButtonPressed->position.x, mouseButtonPressed->position.y) && windowPaused)
                {
                    windowPaused = false;
                    background.ResetBackground();
                    scoreManager.StartNewClock();
                    hittableObject.ResetObject();
                    character.ResetCharacter();
                }

                std::cout << "X Pos: " << mouseButtonPressed->position.x << "\n";
                std::cout << "Y Pos: " << mouseButtonPressed->position.y << "\n";
            }
        }

        background.DrawBackground(window);
        character.DrawCharacter(window);
        hittableObject.DrawObject(window);
        
        if (hittableObject.IsCollided(character.GetSprite()))
        {
            windowPaused = true;
        }

        if (!windowPaused)
        {
            float delta = clock.restart().asSeconds();

            background.MoveBackground(delta);

            hittableObject.MoveObject(delta * background.GetRoadSpeed());

            hittableObject.RelocateSprite();
        }
        else
        {
            gameOverScreen.UpdateScore(scoreManager);
            gameOverScreen.DrawWindow(window);
        }

        window.display();
    }
}

/* 
*  TODO:
*  1. Make a button to restart game
*  2. Center the game over text in the game over screen
*  3. Make a current time alive for scoring and a high score that appears on the game over screen
*/
