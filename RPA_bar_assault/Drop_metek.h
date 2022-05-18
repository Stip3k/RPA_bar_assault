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
public:
    Drop_metek(sf::Vector2f vel);

    void upodobi(sf::RenderWindow& okno);

    sf::FloatRect getDrMet();

    void setPoz(sf::Vector2f novP);
};

