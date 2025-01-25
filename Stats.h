#pragma once 
#include <sfml/Graphics.hpp>

class Stats {
private:
    sf::Text frameRate;
    sf::Clock clock;

    int nFrames = 0;
    float deltaTimeGap = 0.;
    float updateTime = 1000.;
    int x = 10;
    int y = 10;

public:
    sf::Font font;
    float deltaTime = 0.;
    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};