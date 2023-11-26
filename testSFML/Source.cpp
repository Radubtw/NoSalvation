#include"Player.h"
#include"Collider.h"
#include"Platform.h"
#include"Menu.h"
#define WindowHeight  600;
#define WindowLength  800;

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "No Salvation");
    float dt = 0.02f;
    bool onGround = false;
    Player player;

    std::vector<Platform> platforms;
    platforms.push_back(Platform(sf::Vector2f(30.0f, 60.0f), sf::Vector2f(200.0f, 400.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 60.0f), sf::Vector2f(296.0f, 400.0f)));

    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(0.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(48.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(96.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(144.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(192.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(240.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(288.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(336.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(384.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(432.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(480.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(528.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(576.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(624.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(672.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(720.0f, 552.0f)));
    platforms.push_back(Platform(sf::Vector2f(30.0f, 70.0f), sf::Vector2f(768.0f, 552.0f)));



   // platforms.push_back(Platform(sf::Vector2f(120.0f, 50.0f), sf::Vector2f(650.0f, 450.0f)));
    platforms.push_back(Platform(sf::Vector2f(4000.0f, 50.0f), sf::Vector2f(-1000.0f, 590.0f)));

    //platforms.push_back(Platform(sf::Vector2f(50.0f, 1000.0f), sf::Vector2f(750.0f, 0.0f)));

    sf::Texture background;
    //background.setRepeated(true);
    if (!background.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\things\\images\\backgroundTexture.jpg"))
    {
        std::cout << "Failed to load from file";
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);

    
    sf::Texture background2;
    //background.setRepeated(true);
    if (!background.loadFromFile("C:\\Users\\Radu\\source\\repos\\testSFML\\x64\\Debug\\things\\images\\Floor2Copy.jpg"))
    {
        std::cout << "Failed to load from file";
    }

    sf::Sprite backgroundSprite2;

    backgroundSprite2.setTexture(background);

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
        window.draw(backgroundSprite);
        window.clear();
        player.draw(window);
        for (auto& platform : platforms) {
            platform.Draw(window);
        }
        player.update(onGround, platforms, dt);

        window.display();
    }

    return 0;
}
