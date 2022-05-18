#include "Drop_metek.h"

Drop_metek::Drop_metek(sf::Vector2f vel) {
    this->o_dMet.setSize(vel);
    this->o_dMet.setFillColor(sf::Color::Blue);
}

void Drop_metek::upodobi(sf::RenderWindow& okno) {
    okno.draw(this->o_dMet);
}

sf::FloatRect Drop_metek::getDrMet() {
    return this->o_dMet.getGlobalBounds();
}

void Drop_metek::setPoz(sf::Vector2f novP) {
    this->o_dMet.setPosition(novP);
}