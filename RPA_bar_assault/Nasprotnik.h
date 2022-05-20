#pragma once

#include "Izstr_metek.h"

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

    sf::FloatRect getNas();
    void setPoz(sf::Vector2f novP);
    void upodobi(sf::RenderWindow& okno);

    template<class T>
    bool getGlobalBounds(T* r);

    static void setKol(int i);
    static int getKol();
};

