#pragma once
#include "Collider.h"
#include<iostream>
#include <SFML/Graphics.hpp>

class Platform {
private:
    sf::RectangleShape body;
    sf::Texture texture;
    Collider collider;
    sf::Sprite platform_sprite;

public:
    Platform(sf::Vector2f size, sf::Vector2f position)
        : body(size), collider(body) {
        body.setPosition(position);
        body.setSize(size);
        body.setFillColor(sf::Color::White);

        texture.setRepeated(true);

        if (!texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\things\\images\\Floor2.png"))
        {
            std::cout << "Failed to load texture";
        }
        texture.setRepeated(false);
        platform_sprite.setTexture(texture);
        platform_sprite.setScale(0.05, 0.05);
        platform_sprite.setPosition(position);
        
    }


     Collider& GetCollider()  {
        return collider;
     }

    const Collider& GetCollider() const {
        return collider;
    }

    void Draw(sf::RenderWindow& window) {
        window.draw(platform_sprite);
        
    }
};

