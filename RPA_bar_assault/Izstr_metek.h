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
    float velx, vely;

public:
    Izstr_metek* nasl;
    int indeks;

    Izstr_metek();
    ~Izstr_metek();

    float getDes();
    float getLev();
    float getSpod();
    float getZgor();

    void premikStrel(float hit);
    sf::FloatRect getGlobalBounds();
    void upodobi(sf::RenderWindow& okno);
    void setPoz(sf::Vector2f novP);
    bool aliStikEkran(sf::RenderWindow& okno);
    sf::RectangleShape getRec();
};

