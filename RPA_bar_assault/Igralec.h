#pragma once

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
    bool seDotikaDropMet(Drop_metek* dMet);
};

