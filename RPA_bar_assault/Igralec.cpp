#include "Igralec.h"

Igralec::Igralec(sf::Vector2f vel) {
    this->o_igralec.setSize(vel);
    this->o_igralec.setFillColor(sf::Color::Green);
}

Igralec::~Igralec()
{
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

int Igralec::getX() {
    return this->o_igralec.getPosition().x;
}

template<class T>
bool Igralec::getGlobalBounds(T* r) {
    if (this->o_igralec.getGlobalBounds().intersects(r)){
        return true;
    }
    return false;
}