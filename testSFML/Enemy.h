#pragma once
#include"Player.h"
class Enemy
{
private:
	bool isDead;
	sf::Vector2f coords;
	sf::RectangleShape enemyShape;
	sf::Texture enemy_texture;
	sf::Sprite enemy_sprite;

public:
	Enemy();
	Enemy(sf::Vector2f coords);
	static int enemy_count;
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	bool checkIfDead(sf::RenderWindow& window, Player player);
	void draw(sf::RenderWindow& window);
};
