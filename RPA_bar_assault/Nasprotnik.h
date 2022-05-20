#pragma once

#include "Izstr_metek.h"
#include "Drop_metek.h"

class Nasprotnik
{
private:
    sf::RectangleShape o_nas;
    float velx, vely;
    static int kol;

public:
    Nasprotnik* nasl;
    int indeks;

    Nasprotnik();
    ~Nasprotnik();

    sf::FloatRect getGlobalBounds();
    void setPoz(sf::Vector2f novP);
    void upodobi(sf::RenderWindow& okno);

    static void setKol(int i);
    static int getKol();
    sf::RectangleShape getRec();

    template<class T>
    bool getGlobalBounds(T *r) {
        if (this->o_nas.getGlobalBounds().intersects(r->getGlobalBounds())) {
            return true;
        }
        return false;
    }
};

