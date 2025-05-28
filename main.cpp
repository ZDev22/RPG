#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "UI.hpp"
#include <random>

using namespace std;

float playerHealth = 100.f;
float maxPlayerHealth = 100.f;
string area = "grasslands";
bool playerTurn;
vector<bool> enemiesBattling;
bool battling = false;

int generateRandomNumber(short min, short max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1260, 600 }), "RPG");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) { if (event->is<sf::Event::Closed>()) { window.close(); } }

        window.clear(sf::Color(10, 204, 62));
        simulatePlayers(window);
        renderUI(window);

        window.display();
    }
}