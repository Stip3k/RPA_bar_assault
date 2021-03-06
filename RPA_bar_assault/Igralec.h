#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>

#include "Drop_metek.h"
#include "Nasprotnik.h"

class Igralec
{
private:
    sf::RectangleShape o_igralec;

public:
    Igralec(sf::Vector2f vel);
    ~Igralec();

    void upodobi(sf::RenderWindow& okno);
    void move(sf::Vector2f razd);
    void setPoz(sf::Vector2f novaPz);
    int getY();
    int getX();
    
    template<class T>
    bool getGlobalBounds(T* r) {
        if (this->o_igralec.getGlobalBounds().intersects(r->getGlobalBounds())) {
            return true;
        }
        return false;
    }
};