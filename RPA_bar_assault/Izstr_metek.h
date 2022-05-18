#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>

class Izstr_metek
{
private:
    sf::RectangleShape o_iMet;

public:
    Izstr_metek(sf::Vector2f vel) {
        this->o_iMet.setSize(vel);
        this->o_iMet.setFillColor(sf::Color::Blue);
    }

    void premikStrel(float hit) {
        this->o_iMet.move(hit, 0);
    }

    sf::FloatRect getGlobalBounds() {
        return this->o_iMet.getGlobalBounds();
    }

    void upodobi(sf::RenderWindow& okno) {
        okno.draw(this->o_iMet);
    }

    void setPoz(sf::Vector2f novP) {
        this->o_iMet.setPosition(novP);
    }
};

