#include "Player.h"

Player::Player() : collider(rectangle)
{
	coords.x = 400.f;
	coords.y = 500.f;
	x_velocity = 0.0f;
	y_velocity = 0.0f;

	rectangle.setSize(sf::Vector2f(50.0f, 50.0f));
	rectangle.setPosition(coords);
	rectangle.setFillColor(sf::Color::Green);
}

 Player::Player(sf::Vector2f position): y_velocity(0.0f), x_velocity(0.0f), coords(position), rectangle(sf::Vector2f(50.0f, 50.0f)), collider(rectangle) {
        rectangle.setPosition(position);
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
void Player::setXvelocity(float x_velocity)
{
    this->x_velocity = x_velocity;
}

Collider& Player::getCollider()
{
	return collider;
}

//void Player::update(bool& isOnGround, std::vector<Platform> platforms)
//{
//
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//		if (this->coords.y < 600 - 50)
//		{
//			if (this->y_velocity < 0)
//				this->y_velocity = 0;
//			this->y_velocity += 0.0001f;
//			this->coords.y += this->y_velocity;
//			rectangle.setPosition(coords);
//		}
//		else y_velocity = 0.0f;
//
//
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (isOnGround)) {
//		if (this->coords.y > 0)
//		{
//			if (this->y_velocity > 0)
//				this->y_velocity = 0;
//			this->y_velocity -= 0.5f;
//			this->coords.y += this->y_velocity;
//			rectangle.setPosition(coords);
//			isOnGround = false;
//		}
//		else y_velocity = 0.0f;
//
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//		if (this->coords.x > 0)
//		{
//			if (this->x_velocity > 0)
//				this->x_velocity = 0;
//			this->x_velocity -= 0.0001f;
//			this->coords.x += this->x_velocity;
//			rectangle.setPosition(coords);
//		}
//		else x_velocity = 0.0f;
//
//	}
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//		if (this->coords.x < 800 - 50)
//		{
//			if (this->x_velocity < 0)
//				this->x_velocity = 0;
//			this->x_velocity += 0.0001f;
//			this->coords.x += this->x_velocity;
//			rectangle.setPosition(coords);
//
//		}
//		else x_velocity = 0.0f;
//
//	}
//	if (this->coords.y > 550)
//		isOnGround = true;
//	if (this->getYcoord() < 550 && !isOnGround)
//	{
//		this->setYvelocity(this->getYvelocity() + 0.001f);
//		this->coords.y += this->y_velocity;
//		rectangle.setPosition(coords);
//	}
//
//		/*for (auto& platform : platforms) {
//			if (collider.CheckCollision(platform.GetCollider(), 0.0f))
//			{
//				isOnGround = true;
//				this->setYvelocity(0.0f);
//				rectangle.setPosition(rectangle.getPosition().x, platform.GetCollider().GetPosition().y - rectangle.getSize().y / 2.0f);
//
//			}
//			else if (this->coords.y < 550)
//				isOnGround = false;
//				
//		}*/
//
//	for (const auto& platform : platforms) {
//		const Collider& platformCollider = platform.GetCollider();
//
//		if (collider.CheckCollision(const_cast<Collider&>(platformCollider), 0.0f)) {
//			isOnGround = true;
//
//			y_velocity = 0.0f;
//
//			coords.y = platformCollider.GetPosition().y - rectangle.getSize().y / 2.0f;
//		}
//	}
//
//}

void Player::update(bool& onGround, const std::vector<Platform>& platforms, float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        x_velocity = -10.0f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        x_velocity = 10.0f; 
    }
    else {
        x_velocity = 0.0f; 
    }

    if (onGround && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        y_velocity = -50.0f;
        onGround = false; 
    }

    y_velocity += 10.0f * deltaTime; 
    coords.x += x_velocity * deltaTime; 
    coords.y += y_velocity * deltaTime; 

    
    collider.Move(x_velocity * deltaTime, y_velocity * deltaTime);

    for (const auto& platform : platforms) {
        const Collider& platformCollider = platform.GetCollider();
        if (collider.CheckCollision(const_cast<Collider&>(platformCollider), 0.0f)) {
            onGround = true;
            y_velocity = 0.0f; 
            coords.y = platformCollider.GetPosition().y - collider.GetSize().y / 2.0f;
        }
    }
}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(rectangle);
}
