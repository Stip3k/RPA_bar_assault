#pragma once
class Drop_metek
{
protected:
    sf::RectangleShape coin;
public:
    Coin(sf::Vector2f size);

    void upodobi(sf::RenderWindow& window);

    sf::FloatRect getMeje();

    void setPoz(sf::Vector2f newPos);
};

