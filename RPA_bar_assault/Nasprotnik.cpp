#include "Nasprotnik.h"

int Nasprotnik::kol = 0;

Nasprotnik::Nasprotnik() {
    this->velx = 30.0f;
    this->vely = 30.0f;
    this->o_nas.setSize({ this->velx, this->vely });
    this->o_nas.setFillColor(sf::Color::Yellow);
    this->nasl = NULL;
    this->indeks = 0;
}

Nasprotnik::~Nasprotnik()
{
}

sf::FloatRect Nasprotnik::getNas()
{
    return this->o_nas.getGlobalBounds();
}

void Nasprotnik::setPoz(sf::Vector2f novP) {
    this->o_nas.setPosition(novP);
}

template<class T>
bool Nasprotnik::getGlobalBounds(T* r) {
    if (this->o_nas.getGlobalBounds().intersects(r->getGlobalBounds())) {
        return true;

    }
    return false;
}

void Nasprotnik::upodobi(sf::RenderWindow& okno) {
    okno.draw(this->o_nas);
}

void Nasprotnik::setKol(int i) {
    kol = i;
}

int Nasprotnik::getKol() {
    return kol;
}