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
    stats.Initialize();

    //----------------------------------------------------Initialization--------------------------------------------------

    //---------------------------------------------------------Load-------------------------------------------------------
    player.Load();
    stats.Load();
    //---------------------------------------------------------Load-------------------------------------------------------

    while (window.isOpen()) {
        //------------------------------------------------------Update-----------------------------------------------------
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        player.Update(stats.deltaTime, window);
        stats.Update();
        //------------------------------------------------------Update-----------------------------------------------------

        //------------------------------------------------------Render-----------------------------------------------------
        window.clear(sf::Color::Black);

        player.Draw(window);
        stats.Draw(window);

        window.display();
        //------------------------------------------------------Render-----------------------------------------------------
    }
}