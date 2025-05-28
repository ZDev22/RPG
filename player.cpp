#include "player.hpp"
#include "main.hpp"
#include "enemies.hpp"
#include <iostream>

sf::Texture playerTexture("p11.png");
sf::Sprite playerSprite(playerTexture);

sf::Vector2f playerPosition;

sf::Clock animation;

bool canBattle;
bool attacking = false;
bool keyPressed = false;

short target;
short damage = 2;

short animationFrame = 1;

void simulatePlayers(sf::RenderWindow& window) {

	if (!battling) {

		playerSprite.setScale(sf::Vector2f(2.f, 2.f));

		canBattle = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) { playerPosition.y -= 2.f; canBattle = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) { playerPosition.y += 2.f; canBattle = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) { playerPosition.x -= 2.f; canBattle = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) { playerPosition.x += 2.f; canBattle = true; }

		playerSprite.setPosition(playerPosition);

		if (canBattle) { 
			if (generateRandomNumber(1, 400) == 1) {
				battling = true;
				generateEnemies();
			}
			else if (animation.getElapsedTime().asMilliseconds() > 100) {
				animation.restart();
				animationFrame++;
				if (animationFrame > 4) { animationFrame = 1; }
			}
			playerTexture.loadFromFile("p1" + to_string(animationFrame) + ".png");
		}
		else { playerTexture.loadFromFile("p11.png"); }
	}
	else {
		playerTexture.loadFromFile("p1B.png");
		playerSprite.setScale(sf::Vector2f(20.f, 20.f));
		playerSprite.setPosition(sf::Vector2f(0.f, 350.f));

		simulateEnemies(window);

		if (playerTurn) {
			if (attacking) {
				target = -1;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) { if (enemiesBattling[0] == true) { target = 0; } }
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) { if (enemiesBattling[1] == true) { target = 1; } }
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) { if (enemiesBattling[2] == true) { target = 2; } }

				if (target >= 0) {

					size_t q = target;
					enemyList[q].health -= ((damage + generateRandomNumber(1, 4)) - enemyList[q].defence);
					if (enemyList[q].health <= 0) { enemiesBattling[q] = false; }
					attacking = false;
					playerTurn = false;
					keyPressed = true;

					battling = false;

					for (q = 0; q < enemyList.size(); ++q) { if (enemyList[q].health > 0) { battling = true; } }
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
				if (!keyPressed) { attacking = true; }
			}
			else { keyPressed = false; }
		}
	}

	playerSprite.setTexture(playerTexture);
	window.draw(playerSprite);
}