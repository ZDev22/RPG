#include "enemies.hpp"
#include "player.hpp"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

vector<Enemies> enemyList;

sf::Texture enemyTexture("p1B.png");
sf::Sprite enemySprite(enemyTexture);

sf::RectangleShape healthBar;

size_t i;

void createEnemy(string name, short damage, float health, short defence) {
    Enemies enemy;
    enemy.name = name;
    enemy.damage = damage;
    enemy.health = health;
    enemy.maxHealth = health;
    enemy.defence = defence;

    enemyList.push_back(enemy);
}

void generateEnemies() {
    playerTurn = true;
    enemyList.clear();

    enemiesBattling = { false, false, false };

    if (area == "grasslands") {
        for (i = 0; i < generateRandomNumber(1, 3); ++i) {
            switch (generateRandomNumber(1, 10)) {
            case 1: createEnemy("scout", 5, 15.f, 0); break;
            case 2: createEnemy("warrior", 10, 12.f, 0); break;
            case 3: createEnemy("skull", 4, 9.f, 1); break;
            case 4: createEnemy("general", 9, 20.f, 0); break;
            case 5: createEnemy("bat", 12, 7.f, 1); break;
            case 6: createEnemy("snake", 5, 10.f, 0); break;
            case 7: createEnemy("slime", 2, 18.f, 0); break;
            case 8: createEnemy("scavenger", 6, 19.f, 0); break;
            case 9: createEnemy("lurker", 4, 27.f, 0); break;
            case 10: createEnemy("monitor", 15, 10.f, 1); break;
            }
            enemiesBattling[i] = true;
        }
    }
}

void simulateEnemies(sf::RenderWindow& window) {
    if (!playerTurn) { for (i = 0; i < enemyList.size(); ++i) { if (enemyList[i].health > 0) { playerHealth -= enemyList[i].damage; } playerTurn = true; }}

    for (i = 0; i < enemyList.size(); ++i) {

        if (enemyList[i].health > 0) {

            enemyTexture.loadFromFile(enemyList[i].name + ".png");
            enemySprite.setTexture(enemyTexture);
            enemySprite.setScale(sf::Vector2f(10.f, 10.f));
            enemySprite.setPosition(sf::Vector2f(100.f + i * 100.f, 100.f));

            window.draw(enemySprite);

            healthBar.setSize(sf::Vector2f((enemyList[i].health / enemyList[i].maxHealth) * 70.f, 20.f));
            healthBar.setPosition(sf::Vector2f(100.f + (i * 100.f), 60.f));
            healthBar.setFillColor(sf::Color::Green);

            window.draw(healthBar);
        }
    }
}