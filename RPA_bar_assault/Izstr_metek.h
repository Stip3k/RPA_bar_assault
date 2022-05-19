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
    Izstr_metek(sf::Vector2f vel);
    ~Izstr_metek();

    void premikStrel(float hit);
    sf::FloatRect getGlobalBounds();
    void upodobi(sf::RenderWindow& okno);
    void setPoz(sf::Vector2f novP);
};

