#pragma once
#include "Collider.h"
#include <SFML/Graphics.hpp>

class Platform {
private:
    sf::RectangleShape body;
    Collider collider;

public:
    Platform(sf::Vector2f size, sf::Vector2f position)
        : body(size), collider(body) {
        body.setPosition(position);
        body.setFillColor(sf::Color::Magenta);
    }

    void Draw(sf::RenderWindow& window) {
        window.draw(body);
    }

     Collider& GetCollider()  {
        return collider;
    }



    const Collider& GetCollider() const {
        return collider;
    }
};

