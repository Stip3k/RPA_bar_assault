#include "Izstr_metek.h"

Izstr_metek::Izstr_metek() {
    this->velx = 20.0f;
    this->vely = 10.0f;
    this->o_iMet.setSize({ this->velx, this->vely });
    this->o_iMet.setFillColor(sf::Color::Red);
    this->nasl = NULL;
    this->indeks = 0;
}

Izstr_metek::~Izstr_metek() {}

float Izstr_metek::getDes()
{
    return this->o_iMet.getPosition().x + this->velx;
}

float Izstr_metek::getLev()
{
    return this->o_iMet.getPosition().x;
}

float Izstr_metek::getSpod()
{
    return this->o_iMet.getPosition().y + this->vely;
}

float Izstr_metek::getZgor()
{
    return this->o_iMet.getPosition().y;

}

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

bool Izstr_metek::aliStikEkran(sf::RenderWindow& okno)
{
    if (this->getDes() > okno.getSize().x - 10) return 1;
    if (this->getLev() < 10.0f) return 1;
    if (this->getZgor() > okno.getSize().y - 10) return 1;
    if (this->getSpod() < 10.0f) return 1;
    return 0;
}
