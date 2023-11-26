#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
class Collider {
private:
    sf::RectangleShape& body;

public:
    Collider(sf::RectangleShape& body) : body(body) {}

    void Move(float dx, float dy) {
        body.move(dx, dy);
    }

    bool CheckCollision(Collider& other, float push) {
        sf::Vector2f otherPosition = other.GetPosition();
        sf::Vector2f otherHalfSize = other.GetHalfSize();
        sf::Vector2f thisPosition = GetPosition();
        sf::Vector2f thisHalfSize = GetHalfSize();

        float deltaX = otherPosition.x - thisPosition.x;
        float deltaY = otherPosition.y - thisPosition.y;

        float intersectX = std::abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
        float intersectY = std::abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

        if (intersectX < 0.0f && intersectY < 0.0f) {
            push = std::min(std::max(push, 0.0f), 1.0f);

            if (intersectX > intersectY) {
                if (deltaX > 0.0f) {
                    Move(intersectX * (1.0f - push), 0.0f);
                    other.Move(-intersectX * push, 0.0f);
                }
                else {
                    Move(-intersectX * (1.0f - push), 0.0f);
                    other.Move(intersectX * push, 0.0f);
                }
            }
            else {
                if (deltaY > 0.0f) {
                    Move(0.0f, intersectY * (1.0f - push));
                    other.Move(0.0f, -intersectY * push);
                }
                else {
                    Move(0.0f, -intersectY * (1.0f - push));
                    other.Move(0.0f, intersectY * push);
                }

                return true;
            }
        }

        return false;
    }

    sf::Vector2f GetPosition() const {
        return body.getPosition();
    }

    sf::Vector2f GetSize() const {
        return sf::Vector2f(body.getSize().x, body.getSize().y);
    }

    sf::Vector2f GetHalfSize() const {
        sf::FloatRect rect = body.getLocalBounds();
        return sf::Vector2f(rect.width / 2.0f, rect.height / 2.0f);
    }

    sf::RectangleShape GetDebugShape() const {
        sf::RectangleShape debugShape = body;
        debugShape.setFillColor(sf::Color::Transparent);
        debugShape.setOutlineColor(sf::Color::Red);
        debugShape.setOutlineThickness(1.0f);
        return debugShape;
    }
};


