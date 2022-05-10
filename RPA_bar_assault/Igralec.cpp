#include "Igralec.h"
#include "Drop_metek.h"

Igralec::Igralec(sf::Vector2f vel) {
    this->o_igralec.setVel(vel);
    this->o_igralec.setFillColor(sf::Color::Green);
}

void Igralec::upodobi(sf::RenderWindow& okno) {
    okno.draw(this->o_igralec);
}

void Igralec::move(sf::Vector2f razd) {
    this->o_igralec.move(razd);
}

void Igralec::setPoz(sf::Vector2f novaPz) {
    this->o_igralec.setPosition(novaPz);
}

int Igralec::getY() {
    return this->o_igralec.getPosition().y;
}

bool Igralec::seDotikaDropMet(Drop_metek* dMet) {
    if (this->o_igralec.getGlobalBounds().intersects(dMet->getGlobalBounds())) {
        return true;
    }
    return false;
}