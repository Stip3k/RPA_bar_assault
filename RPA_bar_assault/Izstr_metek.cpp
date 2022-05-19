#include "Izstr_metek.h"

Izstr_metek::Izstr_metek(sf::Vector2f vel) {
    this->o_iMet.setSize(vel);
    this->o_iMet.setFillColor(sf::Color::Blue);
}

Izstr_metek::~Izstr_metek() {}

void Izstr_metek::premikStrel(float hit) {
    this->o_iMet.move(hit, 0);
}

sf::FloatRect Izstr_metek::getGlobalBounds() {
    return this->o_iMet.getGlobalBounds();
}

void Izstr_metek::upodobi(sf::RenderWindow& okno) {
    okno.draw(this->o_iMet);
}

void Izstr_metek::setPoz(sf::Vector2f novP) {
    this->o_iMet.setPosition(novP);
}