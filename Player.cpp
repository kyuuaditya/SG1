#include "Player.h"
#include <iostream>

void Player::Initialize(){
    movementMap = {
        {sf::Keyboard::W, {sf::Vector2f(0, -1)}}, // up
        {sf::Keyboard::A, {sf::Vector2f(-1, 0)}}, // left
        {sf::Keyboard::S, {sf::Vector2f(0, 1)}}, // down
        {sf::Keyboard::D, {sf::Vector2f(1, 0)}} // right
    };
    
    size = sf::Vector2i(width, height);
    sprite.scale(sf::Vector2f(3, 3));
}

void Player::Load(){
    if (texture.loadFromFile("assets/player/texture/spriteSheet.png")) {
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(20, 400));
        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        std::cout << "Player texture loaded!" << std::endl;
    }
    else {
        std::cout << "Player texture failed to loaded!" << std::endl;
    }
}

void Player::Update(float deltaTime,  sf::RenderWindow& window){
    for (const auto& [key,movement]:movementMap){
        if (sf::Keyboard::isKeyPressed(key)){
            sf::Vector2f position = sprite.getPosition();
            sprite.setPosition(position + movement.vector * playerSpeed * deltaTime);
            sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
            sf::FloatRect bounds = sprite.getGlobalBounds();
            if (bounds.left < 10){
                sprite.setPosition(10, sprite.getPosition().y);
            }
            if (bounds.top < 10){
                sprite.setPosition(sprite.getPosition().x, 10);
            }
            if (bounds.left + bounds.width > window.getSize().x - 10){
                sprite.setPosition(window.getSize().x - bounds.width - 10, sprite.getPosition().y);
            }
            if (bounds.top + bounds.height > window.getSize().y - 10){
                sprite.setPosition(sprite.getPosition().x, window.getSize().y - bounds.height - 10);
            }
        }
    }
}

void Player::Draw(sf::RenderWindow& window){
    window.draw(sprite);
}