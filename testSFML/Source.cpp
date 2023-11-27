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
float randomFloatX();
float randomFloatY();
int main() {

    Menu main_menu;
    

    sf::RenderWindow window(sf::VideoMode(1920,1080), "No Salvation");
    float dt = 0.03f;
    bool onGround = false;
    Player player;
    std::vector<Enemy> enemies;
    std::vector<Platform> platforms;
   
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(200.0f, 600.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(600.0f, 700.0f)));
    //floor
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(0.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(96.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(192.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(288.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(384.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(480.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(576.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(672.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(768.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(864.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(960.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(1056.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(1152.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(1248.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(1344.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(1440.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(1536.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(1632.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(1728.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(1824.0f, 990.0f)));
    platforms.push_back(Platform(sf::Vector2f(96.0f, 96.0f), sf::Vector2f(11920.0f, 990.0f)));
    //floor

    sf::Texture floor_placeholder;
    if (!floor_placeholder.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\Floor2.png"))
    {
        std::cout << "Failed to load from file";
    }
    floor_placeholder.setRepeated(true);
    sf::Sprite floor_placeholder_Sprite;

    floor_placeholder_Sprite.setTexture(floor_placeholder);
    floor_placeholder_Sprite.setScale(0, 0);

    sf::Texture background;
    if (!background.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\background2.png"))
    {
        std::cout << "Failed to load from file";
    }
    background.setRepeated(true);
    sf::Sprite backgroundSprite;

    backgroundSprite.setTexture(background);
    backgroundSprite.setScale(7, 3);

    sf::Font font_scor;
    if (!font_scor.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\ASTERU.ttf"))
    {
        std::cout << "failed to load from file";
    }
    sf::Text text;

    text.setFont(font_scor); 
    text.setString("SCORE: 0");
    text.setCharacterSize(32); 
    text.setPosition(1700, 50);
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
                main_menu.setPlayButton0();
            }
        }
        //std::cout << sf::Mouse::getPosition(window).x<<std::endl;
        //std::cout << player.getXcoord() << std::endl;
        while (!main_menu.game_start(window))
        {
            if (main_menu.game_exit(window))
            {
                window.close();
            }
            window.clear();
            main_menu.draw(window);
            window.display();
        }

        if (enemies[0].enemy_count < 4)
        {
            int check = 1;
            float enemy_x = randomFloatX();
            float enemy_y = randomFloatY();
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
            window.draw(floor_placeholder_Sprite);
            
            for (auto& platform : platforms) {
                platform.Draw(window);
            }
            player.draw(window);

            for (int i = 0; i < enemies.size(); i++)
            {
                enemies[i].draw(window);
                if (enemies[i].checkIfDead(window, player))
                {
                    enemies.erase(enemies.begin() + i);
                    player.score++;
                    std::cout <<std::endl<< "Score: " << player.score<<std::endl;
                }
            }

            

            window.draw(text);
            
            player.update(onGround, platforms, dt);

            window.display();
    }
    
    return 0;
}

float randomFloatX()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 1800);
    return dist(gen);
}
float randomFloatY()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 1000);
    return dist(gen);
}

std::vector<Platform> platform_generation(std::vector<Platform> platforms)
{

    return platforms;
}
