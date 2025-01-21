#include <sfml/Graphics.hpp>
#include <math.h>
#include "Player.h"
#include "Enemy_0.h"
#include "Stats.h"
#include "Main_menu.h"

int main() {
    //----------------------------------------------------Initialization--------------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Why", sf::Style::Default);
    window.setFramerateLimit(144);
    window.setVerticalSyncEnabled(true);

    Player player;
    Enemy_0 enemy;
    Stats stats;
    Main_menu main_menu;

    player.Initialize();
    sf::Clock clock;
    float deltaTime = 0.;

    //----------------------------------------------------Initialization--------------------------------------------------

    //---------------------------------------------------------Load-------------------------------------------------------
    player.Load();
    //---------------------------------------------------------Load-------------------------------------------------------

    while (window.isOpen()) {
        //------------------------------------------------------Update-----------------------------------------------------
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        // player.Update(0.1f,sf::Vector2f(0,0),window);

        sf::Time deltaTimeTimer = clock.restart();
        deltaTime = deltaTimeTimer.asMicroseconds() / 1000.;
        player.Update(deltaTime, window);
        //------------------------------------------------------Update-----------------------------------------------------

        //------------------------------------------------------Render-----------------------------------------------------
        window.clear(sf::Color::Black);
        player.Draw(window);
        window.display();
        //------------------------------------------------------Render-----------------------------------------------------
    }
}