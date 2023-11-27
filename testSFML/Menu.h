#pragma once
#include"Button.h"
class Menu {
private:
	Button play_button;
	Button exit_button;
public:
	Menu() 
		: play_button(800.0f, 400.0f, 300.0f, 80.0f, PLAY), exit_button(800.0f, 500.0f, 300.0f, 80.0f, EXIT) {
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
		play_button.draw(window);
		exit_button.draw(window);
	}
};