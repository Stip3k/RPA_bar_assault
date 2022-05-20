#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>

class Drop_metek
{
private:
    sf::RectangleShape o_dMet;
    float velx, vely;

public:
    Drop_metek* nasl;
    int indeks;

    Drop_metek();

    sf::RectangleShape getRec();
    void upodobi(sf::RenderWindow& okno);
    sf::FloatRect getGlobalBounds();
    void setPoz(sf::Vector2f novP);

};

