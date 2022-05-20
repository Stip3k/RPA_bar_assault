#include "Drop_metek.h"

Drop_metek::Drop_metek() {
    this->velx = 15.0f;
    this->vely = 15.0f;
    this->o_dMet.setSize({ this->velx, this->vely });
    this->o_dMet.setFillColor(sf::Color::Blue);
    this->nasl = NULL;
    this->indeks = 0;
}

void Drop_metek::upodobi(sf::RenderWindow& okno) {
    okno.draw(this->o_dMet);
}

sf::FloatRect Drop_metek::getGlobalBounds() {
    return this->o_dMet.getGlobalBounds();
}

void Drop_metek::setPoz(sf::Vector2f novP) {
    this->o_dMet.setPosition(novP);
}