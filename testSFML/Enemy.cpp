#include "Enemy.h"

Enemy::Enemy()
{
	coords.x = 500;
	coords.y = 500;
	isDead = 0;
	enemyShape.setSize(sf::Vector2f(50.0f, 50.0f));
	enemyShape.setFillColor(sf::Color::Red);
	enemyShape.setPosition(coords);
	enemy_count++;

	if (!enemy_texture.loadFromFile("aku.png"))
	{
		std::cout << "Failed to load from file!";
	}
	enemySprite.setTexture(enemy_texture);
}

Enemy::Enemy(sf::Vector2f coords)
{
	this->coords.x = coords.x;
	this->coords.y = coords.y;
	isDead = 0;
	enemyShape.setSize(sf::Vector2f(80.0f, 80.0f));
	enemyShape.setFillColor(sf::Color::Red);
	enemyShape.setPosition(coords);
	enemy_count++;

	if (!enemy_texture.loadFromFile("C:/Users/Radu/source/repos/testSFML/x64/Debug/aku.png"))
	{
		std::cout << "Failed to load from file!";
	}
	
	enemyShape.setTexture(&enemy_texture);
}

int Enemy::enemy_count = 0;

sf::Vector2f Enemy::getPosition()
{
	return enemyShape.getPosition();
}

sf::Vector2f Enemy::getSize()
{
	return enemyShape.getSize();
}
bool Enemy::checkIfDead(sf::RenderWindow& window, Player player)
{
	sf::Vertex vertices[] =
	{
		sf::Vertex(sf::Vector2f(player.getXcoord(), player.getYcoord()), sf::Color::Green, sf::Vector2f(100,  10)),
		sf::Vertex(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y), sf::Color::Green, sf::Vector2f(100, 10)),

	};
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		float mouse_x = sf::Mouse::getPosition(window).x;
		float mouse_y = sf::Mouse::getPosition(window).y;
		window.draw(vertices, 2, sf::LinesStrip);

		if (mouse_x > coords.x && mouse_x < coords.x + enemyShape.getSize().x)
		{
			if (mouse_y > coords.y && mouse_y < coords.y + enemyShape.getSize().y)
			{
				isDead = 1;
				enemy_count--;
			}
		}
	}
	return isDead ?  1 :  0;
}

void Enemy::draw(sf::RenderWindow& window)
{
	if (isDead == 0)
	{
		window.draw(enemyShape);
	}
}


