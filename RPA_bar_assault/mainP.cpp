/*int main() {
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 755, (sf::VideoMode::getDesktopMode().height / 2) - 390);

    window.create(sf::VideoMode(1500, 700), "SFML Tutorial", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    //Define Objects:
    Player player(sf::Vector2f(50, 50));
    Enemy enemy(sf::Vector2f(50, 50));
    std::vector<Bullet> bulletVec;


    bool isFiring = false;

    //Main Loop:
    while (window.isOpen()) {

        sf::Event Event;

        //Event Loop:
        while (window.pollEvent(Event)) {
            switch (Event.type) {

            case sf::Event::Closed:
                window.close();
            }

            int moveSpeed = 6;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player.move(sf::Vector2f(0, -moveSpeed));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player.move(sf::Vector2f(0, moveSpeed));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.move(sf::Vector2f(-moveSpeed, 0));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player.move(sf::Vector2f(moveSpeed, 0));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                isFiring = true;
            }

        }

        window.clear();
        if (isFiring == true) {
            Bullet newBullet(sf::Vector2f(50, 5));
            newBullet.setPos(sf::Vector2f(player.getX(), player.getY()));
            bulletVec.push_back(newBullet);
            isFiring = false;
        }

        for (int i = 0; i < bulletVec.size(); i++) {
            bulletVec[i].draw(window);
            bulletVec[i].fire(3);
        }

        for (int i = 0; i < bulletVec.size(); i++) {
            enemy.checkColl(bulletVec[i]);
        }

        player.draw(window);
        enemy.draw(window);
        window.display();
    }
}*/