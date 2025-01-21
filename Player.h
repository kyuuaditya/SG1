#pragma once 
#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Texture texture;
    struct Movement {
        sf::Vector2f vector;
    };
    std::map<sf::Keyboard::Key, Movement> movementMap;

    int height = 64;
    int width = 64;
    sf::Vector2i size;
    float playerSpeed = 1.0f;

public:
    sf::Sprite sprite;
    int xIndex = 0;
    int yIndex = 0;

public:
    void Initialize();
    void Load();
    void Update(float deltaTime, sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);
};