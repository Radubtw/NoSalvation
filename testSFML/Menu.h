#pragma once
#include"Button.h"
class Menu {
private:
	Button play_button;
	Button exit_button;
	sf::RectangleShape titleShape;
	sf::Sprite title;
	sf::Texture title_texture;
public:
	Menu() 
		: play_button(800.0f, 400.0f, 300.0f, 80.0f, PLAY), exit_button(800.0f, 500.0f, 300.0f, 80.0f, EXIT) {
		titleShape.setSize(sf::Vector2f(300.0f, 200.0f));
		if (!title_texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\title2.png"))
		{
			std::cout << "failed to load from file";
		}
		titleShape.setScale(2.0f, 2.5f);
		titleShape.setTexture(&title_texture);
		titleShape.setPosition(sf::Vector2f(650.0f, 200.0f));
	}

	bool game_start(sf::RenderWindow &window)
	{
		play_button.isButtonClicked(window);
		return play_button.getButtonClicked();
	}

	bool game_exit(sf::RenderWindow& window)
	{
		exit_button.isButtonClicked(window);
		return exit_button.getButtonClicked();
	}

	void setPlayButton0()
	{
		play_button.setButtonClicked0();
	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(titleShape);
		play_button.draw(window);
		exit_button.draw(window);
	}
};