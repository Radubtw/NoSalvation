#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Config.hpp>
#include "Collider.h"
#include "Platform.h"


class Player
{
private:
	float y_velocity;
	float x_velocity;
	sf::Vector2f coords;
	sf::RectangleShape rectangle;
	sf::Texture texture;
	Collider collider;
	bool facing_right;
public:
	int score;
	int health;


public:
	Player();
	Player(sf::Vector2f);

	void draw(sf::RenderWindow& window);

	float getXcoord();
	float getYcoord();
	void setXCoord(float);
	void setYCoord(float);
	float getYvelocity();
	float getXvelocity();
	void setYvelocity(float);
	void setXvelocity(float);
	bool getFacingRight();
	Collider& getCollider();

	void update(bool&, const std::vector<Platform>&, float);
};

