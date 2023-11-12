#include "Player.h"

Player::Player()
{
	coords.x = 400.f;
	coords.y = 500.f;
	x_velocity = 0.0f;
	y_velocity = 0.0f;

	rectangle.setSize(sf::Vector2f(50.0f, 50.0f)); // Set the size of the player's rectangle
	rectangle.setPosition(coords);
	rectangle.setFillColor(sf::Color::Green);
}

Player::Player(sf::Vector2f coords)
{
	x_velocity = 0.1f;
	y_velocity = 0.1f;

	rectangle.setSize(sf::Vector2f(50.0f, 50.0f)); // Set the size of the player's rectangle
	rectangle.setPosition(coords);
	rectangle.setFillColor(sf::Color::Green);
}

float Player::getXcoord()
{
	return coords.x;
}

float Player::getYcoord()
{
	return coords.y;
}

void Player::setXCoord(float x)
{
	this->coords.x = x;
}
void Player::setYCoord(float y)
{
	this->coords.y = y;
}
float Player::getYvelocity()
{
	return this->y_velocity;
}
void Player::setYvelocity(float y_velocity)
{
	this->y_velocity = y_velocity;
}

void Player::update(bool& isJumping)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (this->coords.y < 600 - 50)
		{
			if (this->y_velocity < 0)
				this->y_velocity = 0;
			this->y_velocity += 0.001f;
			this->coords.y += this->y_velocity;
			rectangle.setPosition(coords);
		}
		else y_velocity = 0.0f;


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& (!isJumping)) {
		if (this->coords.y > 0)
		{
			if (this->y_velocity > 0)
				this->y_velocity = 0;
			this->y_velocity -= 0.5f;
			this->coords.y += this->y_velocity;
			rectangle.setPosition(coords);
			isJumping = true;
		}
		else y_velocity = 0.0f;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (this->coords.x > 0)
		{
			if (this->x_velocity > 0)
				this->x_velocity = 0;
			this->x_velocity -= 0.001f;
			this->coords.x += this->x_velocity;
			rectangle.setPosition(coords);
		}
		else x_velocity = 0.0f;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (this->coords.x < 800 - 50)
		{
			if (this->x_velocity < 0)
				this->x_velocity = 0;
			this->x_velocity += 0.001f;
			this->coords.x += this->x_velocity;
			rectangle.setPosition(coords);

		}
		else x_velocity = 0.0f;

	}
	if (this->coords.y > 550)
		isJumping = false;
	if (this->getYcoord() < 550 && isJumping)
	{
		this->setYvelocity(this->getYvelocity() + 0.001f);
		this->coords.y += this->y_velocity;
		rectangle.setPosition(coords);
	}


}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
}
