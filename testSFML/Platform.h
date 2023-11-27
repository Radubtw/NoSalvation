#pragma once
#include "Collider.h"
#include<iostream>
#include <SFML/Graphics.hpp>

class Platform {
private:
    sf::RectangleShape body;
    sf::Texture platform_texture;
    Collider collider;
    sf::Sprite platform_sprite;

public:
    Platform(sf::Vector2f size, sf::Vector2f position)
        : body(size), collider(body) {
        body.setPosition(position);
        body.setSize(size);
        body.setFillColor(sf::Color::White);

       platform_texture.setRepeated(true);

        if (!platform_texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\Floor2.png"))
        {
            std::cout << "Failed to load texture";
        }
        platform_texture.setRepeated(true);
        platform_sprite.setTexture(platform_texture);
        platform_sprite.setScale(0.06f, 0.06f);
        platform_sprite.setPosition(position);
        
    }


     Collider& GetCollider()  {
        return collider;
     }

    const Collider& GetCollider() const {
        return collider;
    }
    sf::Vector2f getPosition()
    {
        return body.getPosition();
    }
    sf::Vector2f getSize()
    {
        return body.getSize();
    }
    void Draw(sf::RenderWindow& window) {
        window.draw(platform_sprite);
        
    }
};

