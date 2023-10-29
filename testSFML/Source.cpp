#include"Player.h"
#define WindowHeight  600;
#define WindowLength  800;

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "Platformer-Game");

    bool isJumping = true;
    Player player;


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

        std::cout << sf::Mouse::getPosition(window).y<<std::endl;
        //std::cout << player.getYcoord() << std::endl;
        
        player.update(isJumping);
        window.clear();
        player.draw(window);

        window.display();
    }

    return 0;
}
