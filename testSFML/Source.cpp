#include"Player.h"
#include"Enemy.h"
#include"Collider.h"
#include"Platform.h"
#include"Menu.h"
#include<Windows.h>
#include <random>

#define WindowHeight  600;
#define WindowLength  800;

std::vector<Platform> platform_generation(std::vector<Platform>);
float randomFloat();
int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "No Salvation");
    float dt = 0.02f;
    bool onGround = false;
    Player player;
    std::vector<Enemy> enemies;
    std::vector<Platform> platforms;
   
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(200.0f, 400.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(300.0f, 400.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(0.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(57.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(113.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(169.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(225.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(281.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(337.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(393.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(449.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(505.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(561.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(617.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(673.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(729.0f, 543.0f)));
    platforms.push_back(Platform(sf::Vector2f(60.0f, 60.0f), sf::Vector2f(785.0f, 543.0f)));
    // platforms.push_back(Platform(sf::Vector2f(120.0f, 50.0f), sf::Vector2f(650.0f, 450.0f)));
    platforms.push_back(Platform(sf::Vector2f(4000.0f, 50.0f), sf::Vector2f(-1000.0f, 590.0f)));
    //platforms.push_back(Platform(sf::Vector2f(50.0f, 1000.0f), sf::Vector2f(750.0f, 0.0f)));
    //platforms = platform_generation(platforms);

    sf::Texture background;
    if (!background.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\background2.png"))
    {
        std::cout << "Failed to load from file";
    }
    background.setSmooth(true);
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    backgroundSprite.setScale(2.6f, 1.7f);

    sf::Font font_scor;
    if (!font_scor.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\ASTERU.ttf"))
    {
        std::cout << "failed to load from file";
    }
    sf::Text text;

    text.setFont(font_scor); 
    text.setString("SCORE: 0");
    text.setCharacterSize(24); 
    text.setPosition(600, 50);
    text.setFillColor(sf::Color::Magenta);
    text.setStyle(sf::Text::Bold);
    enemies.push_back(Enemy(sf::Vector2f(400.0f, 450.0f)));



    
    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        //std::cout << sf::Mouse::getPosition(window).x<<std::endl;
      //  std::cout << player.getXcoord() << std::endl;
     
        if (enemies[0].enemy_count < 4)
        {
            int check = 1;
            float enemy_x = randomFloat();
            float enemy_y = randomFloat();
            for (auto& platform : platforms)
            {
                if (enemy_x < platform.getPosition().x - platform.getSize().x || enemy_x > platform.getPosition().x + platform.getSize().x)
                {
                    if (enemy_y < platform.getPosition().y - platform.getSize().y || enemy_y > platform.getPosition().y + platform.getSize().y)
                    {
                        check++;
                    }
                }
            }
            for (auto& enemy : enemies)
            {
                if (enemy_x < enemy.getPosition().x - enemy.getSize().x || enemy_x > enemy.getPosition().x + enemy.getSize().x)
                {
                    if (enemy_y < enemy.getPosition().y - enemy.getSize().y || enemy_y > enemy.getPosition().y + enemy.getSize().y)
                    {
                        check++;
                    }
                }
            }
           // std::cout << enemies.size() + platforms.size() <<std::endl;
            if (check ==  enemies.size() + platforms.size() -2)
            {
                enemies.push_back(Enemy(sf::Vector2f((float)enemy_x, (float)enemy_y)));
            }
        }
        text.setString("SCORE: " + std::to_string(player.score));


            window.clear();
            window.draw(backgroundSprite);
            window.draw(text);
            player.draw(window);

            for (int i = 0; i < enemies.size(); i++)
            {
                enemies[i].draw(window);
                if (enemies[i].checkIfDead(window))
                {
                    enemies.erase(enemies.begin() + i);
                    player.score++;
                    std::cout <<std::endl<< "Score: " << player.score<<std::endl;

                }
               
            }
            for (auto& platform : platforms) {
                platform.Draw(window);
            }
            player.update(onGround, platforms, dt);

            window.display();
    }
    
    return 0;
}

float randomFloat()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 540);
    return dist(gen);
}

std::vector<Platform> platform_generation(std::vector<Platform> platforms)
{

    return platforms;
}
