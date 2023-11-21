#include"Player.h"
#include"Collider.h"
#include"Platform.h"
#define WindowHeight  600;
#define WindowLength  800;

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "Platformer-Game");
    float dt = 0.01f;
    bool isOnGround = false;
    Player player;
    std::vector<Platform> platforms;
    //platforms.push_back(Platform(sf::Vector2f(100.0f, 20.0f), sf::Vector2f(200.0f, 400.0f)));
    //platforms.push_back(Platform(sf::Vector2f(150.0f, 20.0f), sf::Vector2f(480.0f, 530.0f)));
    //platforms.push_back(Platform(sf::Vector2f(120.0f, 20.0f), sf::Vector2f(650.0f, 530.0f)));
    platforms.push_back(Platform(sf::Vector2f(1000.0f, 50.0f), sf::Vector2f(0.0f, 590.0f)));


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
        std::cout << sf::Mouse::getPosition(window).x<<std::endl;
       // std::cout << player.getYcoord() << std::endl;
        
        player.update(isOnGround, platforms, dt);
        for (auto& platform : platforms) {
            player.getCollider().CheckCollision(platform.GetCollider(), 0.0f);
        }
        window.clear();
        player.draw(window);
        for (auto& platform : platforms) {
            platform.Draw(window);
        }
        window.display();
    }

    return 0;
}
