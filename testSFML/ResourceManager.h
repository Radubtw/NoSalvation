#pragma once
#include "SFML/Graphics.hpp"

class ResourceManager {
public:
    static sf::Texture& GetEnemyTexture() {
        static sf::Texture texture;
        if (!texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\enemy.png")) {
           
        }
        return texture;
    }
};


