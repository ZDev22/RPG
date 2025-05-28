#include "UI.hpp"
#include "main.hpp"
#include "player.hpp"
#include "enemies.hpp"
#include <iostream>

sf::RectangleShape bars;

sf::Texture attackTexture("attack.png");
sf::Texture attackEnemyTexture("attackEnemy.png");
sf::Sprite attackSprite(attackTexture);

sf::IntRect rect;

using namespace std;

void renderUI(sf::RenderWindow& window) {
	if (battling) {
		bars.setPosition(sf::Vector2f(0.f, 550.f));

		bars.setSize(sf::Vector2f(204.f, 44.f));
		bars.setFillColor(sf::Color(0, 0, 0));
		window.draw(bars);

		bars.setPosition(sf::Vector2f(2.f, 552.f));
		bars.setSize(sf::Vector2f((playerHealth / maxPlayerHealth) * 200, 40.f));
		bars.setFillColor(sf::Color(36, 128, 20));
		window.draw(bars);

		if (attacking) { attackTexture.loadFromFile("attackEnemy.png"); attackSprite.setTexture(attackEnemyTexture); }
		else { attackTexture.loadFromFile("attack.png"); attackSprite.setTexture(attackTexture); }

		attackSprite.setPosition(sf::Vector2f(800.f, 500.f));
		attackSprite.setScale(sf::Vector2f(3.f, 3.f));
		window.draw(attackSprite);
	}
	else {

	}
}