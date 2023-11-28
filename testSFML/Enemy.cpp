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

	if (!enemy_texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\enemy.png"))
	{
		std::cout << "Failed to load from file!";
	}
	enemyShape.setTexture(&enemy_texture);
	enemyShape.setScale(1.0f, 1.0f);

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
	enemyShape.setScale(1.0f, 1.0f);

	if (!enemy_texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\enemy.png"))
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
		sf::Vertex(sf::Vector2f(player.getXcoord() + 50.0f, player.getYcoord() - 70.0f), sf::Color::Green, sf::Vector2f(100.0f,  10.0f)),
		sf::Vertex(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y), sf::Color::Green, sf::Vector2f(100.0f, 10.0f)),
		sf::Vertex(sf::Vector2f(player.getXcoord() + 50.0f, player.getYcoord() - 71.0f), sf::Color::Green, sf::Vector2f(100.0f,  10.0f)),
		sf::Vertex(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y-1), sf::Color::Green, sf::Vector2f(100.0f, 10.0f)),

	};
	sf::Vertex vertices2[]=
	{

	sf::Vertex(sf::Vector2f(player.getXcoord() - 50.0f, player.getYcoord() - 70.0f), sf::Color::Green, sf::Vector2f(100.0f,  10.0f)),
	sf::Vertex(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y), sf::Color::Green, sf::Vector2f(100.0f, 10.0f)),
	sf::Vertex(sf::Vector2f(player.getXcoord() - 50.0f, player.getYcoord() - 71.0f), sf::Color::Green, sf::Vector2f(100.0f,  10.0f)),
	sf::Vertex(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y-1), sf::Color::Green, sf::Vector2f(100.0f, 10.0f)),
	};
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		float mouse_x = sf::Mouse::getPosition(window).x;
		float mouse_y = sf::Mouse::getPosition(window).y;
		if (player.getFacingRight())
		{
			window.draw(vertices, 4, sf::LinesStrip);
		}
		else
		{
			window.draw(vertices2, 4, sf::LinesStrip);
		}
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
	window.draw(enemyShape);
}


