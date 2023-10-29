#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Config.hpp>



class Player
{
private:
	float y_velocity;
	float x_velocity;
	sf::Vector2f coords;
	sf::RectangleShape rectangle;	


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
	void setXvelocity();

	void update(bool&);
};

