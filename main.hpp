#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <vector>

int generateRandomNumber(short min, short max);

using namespace std;

extern float playerHealth;
extern float maxPlayerHealth;
extern string area;
extern bool playerTurn;
extern short enemies;
extern vector<bool> enemiesBattling;
extern bool battling;

#endif