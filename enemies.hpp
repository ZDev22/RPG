#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include "main.hpp"
#include "SFML/Graphics.hpp"
#include <string>

void generateEnemies();
void simulateEnemies(sf::RenderWindow& window);
void declareList();

struct Enemies {
	string name;
	float health;
	float maxHealth;
	short damage;
	short defence;
};

extern vector<Enemies> enemyList;

#endif