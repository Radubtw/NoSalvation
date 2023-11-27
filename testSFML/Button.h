#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
enum type {PLAY, EXIT};
class Button {
private:
    sf::RectangleShape shape;
    sf::Texture button_texture;
    bool button_clicked;
    type button_type;

public:
    
    Button(float x, float y, float width, float height, type button_type)
    {
        shape.setSize(sf::Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Blue);
        button_clicked = 0;
        if (button_type == type::PLAY)
        {
            if (!button_texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\play_button.png")) {
                std::cout << "failed to load button texture";
            }
            shape.setTexture(&button_texture);
        }
        else if (button_type == type::EXIT)
        {
            if (!button_texture.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\exit_button.png")) {
                std::cout << "failed to load button texture";
            }
            shape.setTexture(&button_texture);
        }
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(shape);
    }

    bool isMouseOver(float x, float y) const {
        return shape.getGlobalBounds().contains(x, y);
    }

    bool isButtonClicked(sf::RenderWindow& window)
    {
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        if (shape.getGlobalBounds().contains(translated_pos)) // Rectangle-contains-point check
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                button_clicked = 1;
                return 1;
            }
        }
    return 0;
    }
    bool getButtonClicked()
    {
        return button_clicked;
    }
    void setButtonClicked0()
    {
        button_clicked = 0;
    }
};