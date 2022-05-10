#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Igralec.h"
#include "Drop_metek.h"
#include "Metek.h"

int main()
{
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(900, 900), "SFML Gravity", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);
    
    Igralec igralec({ 40, 40 });
    Igralec.setPoz({ 50, 700 });

    std::vector<Drop_metek*> dMetVec;
    Izstr_metek dMet1({ 20, 20 });
    Izstr_metek dMet2({ 20, 20 });
    dMetVec.push_back(&coin1);
    dMetVec.push_back(&coin2);

    dMet1.setPoz({ 50, 600 });
    dMet2.setPoz({ 100, 600 });

    //Score Objects:

    int score = 0;

    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    std::ostringstream ssScore;
    ssScore << "Score: " << score;

    sf::Text lblScore;
    lblScore.setCharacterSize(30);
    lblScore.setPosition({ 10, 10 });
    lblScore.setFont(arial);
    lblScore.setString(ssScore.str());

    //Zanka igre:
    while (window.isOpen()) {

        sf::Event Event;

        const float moveSpeed = 0.2;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.move({ 0, -moveSpeed });
            isJumping = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.move({ 0, moveSpeed});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move({ moveSpeed, 0 });
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move({ -moveSpeed, 0 });
        }

        //Event Loop:
        while (window.pollEvent(Event)) {
            switch (Event.type) {

            case sf::Event::Closed:
                window.close();
            default:
            }
        }

        /*
            Preverjamo ali je v stiku z igralcem
        */
        for (int i = 0; i < dMetVec.size(); i++) {
            if (igralec.seDotikaDropMet(dMetVec[i])) {
                dMetVec[i]->setPoz({ 422234, 423432 });
                score++;
                ssScore.str("");
                ssScore << "Score " << score;
                lblScore.setString(ssScore.str());
            }
        }

        window.clear();
        dMet1.upodobi(window);
        window.draw(lblScore);
        dMet2.upodobi(window);
        igralec.upodobi(window);
        window.display();
    }

	return 0;
}