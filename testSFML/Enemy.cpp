#include "Enemy.h"

Enemy::Enemy() //:collider(enemyShape)
{
	coords.x = 500;
	coords.y = 500;
	x_velocity = 0;
	y_velocity = 0;
	isDead = 0;
	damage_dealt = false;
	enemyShape.setSize(sf::Vector2f(400.0f, 106.0f));
	enemyShape.setFillColor(sf::Color::White);
	enemyShape.setPosition(coords);
	enemy_count++;

	/*if (!enemy_texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\enemy.png"))
	{
		std::cout << "Failed to load from file!";
	}*/
	enemyShape.setTexture(&ResourceManager::GetEnemyTexture());
	//enemyShape.setScale(1.0f,1.0f);

}

Enemy::Enemy(sf::Vector2f coords) //:collider(enemyShape)
{
	this->coords.x = coords.x;
	this->coords.y = coords.y;
	x_velocity = 0;
	y_velocity = 0;
	isDead = 0;
	damage_dealt = false;
	enemyShape.setSize(sf::Vector2f(200.0f, 53.0f));
	enemyShape.setFillColor(sf::Color::White);
	enemyShape.setPosition(coords);
	enemy_count++;
	//enemyShape.setScale(1.0f, 1.0f);

	if (!enemy_texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\enemy1.png"))
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

bool Enemy::getDamageDealt()
{
	return damage_dealt;
}

void Enemy::setTexture()
{
	enemyShape.setTexture(&enemy_texture);

}

//Collider& Enemy::getCollider()
//{
//	return collider;
//}

bool Enemy::checkIfDead(sf::RenderWindow& window, Player player)
{

	sf::Vertex vertices[] =
	{
		sf::Vertex(sf::Vector2f(player.getXcoord() + 80.0f, player.getYcoord() - 40.0f), sf::Color::Green, sf::Vector2f(100.0f,  10.0f)),
		sf::Vertex(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y), sf::Color::Green, sf::Vector2f(100.0f, 10.0f)),
		sf::Vertex(sf::Vector2f(player.getXcoord() + 81.0f, player.getYcoord() - 41.0f), sf::Color::Green, sf::Vector2f(100.0f,  10.0f)),
		sf::Vertex(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y-1), sf::Color::Green, sf::Vector2f(100.0f, 10.0f)),

	};
	sf::Vertex vertices2[]=
	{

	sf::Vertex(sf::Vector2f(player.getXcoord() - 80.0f, player.getYcoord() - 40.0f), sf::Color::Green, sf::Vector2f(100.0f,  10.0f)),
	sf::Vertex(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y), sf::Color::Green, sf::Vector2f(100.0f, 10.0f)),
	sf::Vertex(sf::Vector2f(player.getXcoord() - 81.0f, player.getYcoord() - 41.0f), sf::Color::Green, sf::Vector2f(100.0f,  10.0f)),
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
	return isDead;
}

void Enemy::update(Player& player, float dt)
{
	//std::cout << "Player X: " << player.getXcoord() << " _______ Y: " << player.getYcoord() << std::endl;
	if (abs(this->coords.x - player.getXcoord()) < 50)
	{
		this->x_velocity = 0;
		if (!damage_dealt)
		{
			player.health -= 1;
			damage_dealt = true;
		}
	}
	if (abs(this->coords.y - player.getYcoord()) < 30)
	{
		this->y_velocity = 0;
		if (!damage_dealt)
		{
			player.health -= 1;
			damage_dealt = true;
		}
	}

	//if (player.getXcoord() > this->coords.x)
	//	this->x_velocity += 0.006f;
	//else if (player.getXcoord() < this->coords.x)
	//	this->x_velocity -= 0.006f;
	//if (player.getYcoord() > this->coords.y)
	//	this->y_velocity += 0.006f;
	//else if (player.getYcoord() < this->coords.y)
	//	this->y_velocity -= 0.006f;
	if (abs(player.getXcoord() - this->coords.x) > abs(player.getYcoord() - this->coords.y))
	{
		if (player.getXcoord() > this->coords.x)
		{
			this->x_velocity += 0.006f;
		}
		else if (player.getXcoord() < this->coords.x)
		{
			this->x_velocity -= 0.006f;
		}
	}
	else
	{
		if (player.getYcoord() > this->coords.y)
		{
			this->y_velocity += 0.006f;
		}
		else if (player.getYcoord() < this->coords.y)
		{
			this->y_velocity -= 0.006f;
		}
	}

	coords.x += x_velocity * dt;
	coords.y += y_velocity * dt;
	enemyShape.setPosition(coords);
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(enemyShape);
}


