#include "Drop_metek.h"

Drop_Metek::Drop_Metek(sf::Vector2f size) {
    coin.setSize(size);
    coin.setFillColor(sf::Color::Yellow);
}

void Drop_Metek::upodobi(sf::RenderWindow& window) {
    window.draw(coin);
}

sf::FloatRect Drop_Metek::getMeje() {
    return coin.getGlobalBounds();
}

void Drop_Metek::setPoz(sf::Vector2f newPos) {
    coin.setPosition(newPos);
}