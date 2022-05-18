#pragma once

#include "Izstr_metek.h"

class Nasprotnik
{
private:
    sf::RectangleShape o_nas;

public:
    Nasprotnik(sf::Vector2f vel) {
        this->o_nas.setSize(vel);
        this->o_nas.setFillColor(sf::Color::Red);
    }

    sf::FloatRect getNas()
    {
        return this->o_nas.getGlobalBounds();
    }

    void setPoz(sf::Vector2f novP) {
        this->o_nas.setPosition(novP);
    }

    bool getGlobalBounds(Izstr_metek* iMet) {
        if (this->o_nas.getGlobalBounds().intersects(iMet->getGlobalBounds())) {
            return true;
        }
        return false;
    }

    void upodobi(sf::RenderWindow& okno) {
        okno.draw(this->o_nas);
    }
};

