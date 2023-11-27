#include "Player.h"

Player::Player() : collider(rectangle)
{
	coords.x = 400.f;
	coords.y = 500.f;
	x_velocity = 0.0f;
	y_velocity = 0.0f;
    score = 0;

	rectangle.setSize(sf::Vector2f(140.0f, 140.0f));
	rectangle.setPosition(coords);
	rectangle.setFillColor(sf::Color::White);
    rectangle.setScale(1.2, 1.2);
    if (!texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\player3.png"))
    {
        std::cout << "Failed to load from file!";
    }
    rectangle.setTexture(&texture);
    

}

 Player::Player(sf::Vector2f position): y_velocity(0.0f), x_velocity(0.0f), coords(position), rectangle(sf::Vector2f(50.0f, 50.0f)), collider(rectangle) {
        rectangle.setPosition(position);
        rectangle.setFillColor(sf::Color::Green);
        score = 0;

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

void Player::update(bool& onGround, const std::vector<Platform>& platforms, float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        x_velocity = -10.0f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        x_velocity = 10.0f; 
    }
    else {
        x_velocity = 0.0f; 
    }

    if (onGround && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        y_velocity = -70.0f;
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
            coords.y = platformCollider.GetPosition().y - collider.GetHalfSize().y ;
        }
    }
}

void Player::draw(sf::RenderWindow & window)
{
    window.draw(rectangle);
	
}
