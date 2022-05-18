#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

/*
sfml-graphics-d.lib
sfml-audio-d.lib
sfml-network-d.lib
sfml-window-d.lib
sfml-system-d.lib
*/

#include "Drop_metek.h"
#include "Izstr_metek.h"
#include "Igralec.h"
#include "Nasprotnik.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
/*
class Izstr_metek
{
private:
    sf::RectangleShape o_iMet;

public:
    Izstr_metek(sf::Vector2f vel) {
        this->o_iMet.setSize(vel);
        this->o_iMet.setFillColor(sf::Color::Blue);
    }

    void premikStrel(int hit) {
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

class Drop_metek
{
private:
    sf::RectangleShape o_dMet;

public:
    Drop_metek(sf::Vector2f vel) {
        this->o_dMet.setSize(vel);
        this->o_dMet.setFillColor(sf::Color::Blue);
    }

    void upodobi(sf::RenderWindow& okno) {
        okno.draw(this->o_dMet);
    }

    sf::FloatRect getDrMet() {
        return this->o_dMet.getGlobalBounds();
    }

    void setPoz(sf::Vector2f novP) {
        this->o_dMet.setPosition(novP);
    }
};

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

class Igralec
{
private:
    sf::RectangleShape o_igralec;

public:
    Igralec(sf::Vector2f vel) {
        this->o_igralec.setSize(vel);
        this->o_igralec.setFillColor(sf::Color::Green);
    }

    void upodobi(sf::RenderWindow& okno) {
        okno.draw(this->o_igralec);
    }

    void move(sf::Vector2f razd) {
        this->o_igralec.move(razd);
    }

    void setPoz(sf::Vector2f novaPz) {
        this->o_igralec.setPosition(novaPz);
    }

    int getY() {
        return this->o_igralec.getPosition().y;
    }

    int getX() {
        return this->o_igralec.getPosition().x;
    }

    bool getGlobalBound(Drop_metek* dMet) {
        if (this->o_igralec.getGlobalBounds().intersects(dMet->getDrMet())) {
            return true;
        }
        return false;
    }
    //Spremeni return type od nasprotnika pri getglobalbounds
    bool getGlobalBound(Nasprotnik* nas) {
        if (this->o_igralec.getGlobalBounds().intersects(nas->getNas())) {
            return true;
        }
        return false;
    }
};
*/

void zakljuci(sf::RenderWindow& okno, bool smrt)
{
    if (smrt == 0) {
        okno.close();
        //TODO: sharni vrednost stNas in stMet
    }
    else
    {
        okno.close();
        //TODO: znova zacne igro, ponastavi vse vrednosti
    }
}

int main()
{
    //Spremenljivke igre
    bool aliStrela = 0;
    int stNas = 2;
    int stMet = 0;

    sf::RenderWindow okno;
    sf::Vector2i pozOkna((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    okno.create(sf::VideoMode(900, 900), "Barbarian assault!", sf::Style::Titlebar | sf::Style::Close);
    okno.setPosition(pozOkna);
    okno.setKeyRepeatEnabled(true);
    
    Igralec igralec({ 40, 40 });
    igralec.setPoz({ 50, 700 });

    std::vector<Izstr_metek*> iMetVec;
    std::vector<Drop_metek*> dMetVec;
    std::vector<Nasprotnik*> nasVec;

    Drop_metek dMet1({ 20, 20 });
    Drop_metek dMet2({ 20, 20 });
    dMetVec.push_back(&dMet1);
    dMetVec.push_back(&dMet2);

    dMet1.setPoz({ 50, 600 });
    dMet2.setPoz({ 100, 600 });
    
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    std::ostringstream s_stMet;
    s_stMet << "Število nabojev: " << stMet%2;

    sf::Text t_stMet;
    t_stMet.setCharacterSize(30);
    t_stMet.setPosition({ 10, 10 });
    t_stMet.setFont(arial);
    t_stMet.setString(s_stMet.str());

    //Zanka igre:
    while (okno.isOpen()) {

        /*
            Ustvarimo nov objekt razrreda Event,
            nato preverjamo vnos s tipkovnice in
            sprožamo dogodke.
        */

        sf::Event Event;

        const float hit = 0.2f;

        //Event Loop:
        while (okno.pollEvent(Event)) {
            switch (Event.type) {

            case sf::Event::Closed:
                zakljuci(okno, 0);
            default: break;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                igralec.move({ 0, -hit });
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                igralec.move({ 0, hit });
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                igralec.move({ hit, 0 });
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                igralec.move({ -hit, 0 });

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                aliStrela = true;
            }
        }

        /*
        *   1. Dodamo nove nasprotnike glede na stevilo ubitih, vsak ubit nasprotnik
        *      poveèa stNas in za vsakega drugega ustreljenega se pojavi novi nasprotnik
        *      na ekranu.
        *
            2. Preverjamo ali je v stiku z igralcem, nasprotnikom,...

            3. TODO: Sistem za nasprotnike
        */   

        /////Preverjamo ali je igralec streljal, èe je potem ustvarimo novi objekt
        /////in preverjamo ali je kaj zadel, èe zadane nasprotnika poveèamo števec stNas,
        ///// za vsak drugi zadet nasprotnik se bo v igri pojavil še eden nasprotnik.
        if (aliStrela == true) {
            Izstr_metek nMet(sf::Vector2f(50, 5));
            nMet.setPoz(sf::Vector2f(igralec.getX(), igralec.getY()));
            iMetVec.push_back(&nMet);
            aliStrela = false;
            stMet--;
        }

        for (int i = 0; i < iMetVec.size(); i++) {
            iMetVec[i]->upodobi(okno);
            iMetVec[i]->premikStrel(1);
        }

        for (int i = 0; i < nasVec.size(); i++) {
            for (int j = 0; j < iMetVec.size(); j++)
            {
                if (nasVec[i]->getGlobalBounds(iMetVec[j]))
                {
                    //
                }
            }
        }

        /////Preverjamo ali je igralec blizu naboja, pristejemo k stevcu stMet,
        /////to pomeni, da lahko za toliko vec strelja.
        for (int i = 0; i < dMetVec.size(); i++) {
            if (igralec.getGlobalBound(dMetVec[i])) {
                dMetVec[i]->setPoz({ rand() % 870 + 1.0f, rand() % 870 + 1.0f });
                stMet++;
                s_stMet.str("");
                s_stMet << "stMet " << stMet;
                t_stMet.setString(s_stMet.str());
            }
        }
        
        /////preverja ali je igralec v stiku z nasprotnikom,
        /////ker znas samo streljati na daleè te z lahkoto premaga nasprotnik.
        for (int i = 0; i < nasVec.size() % 2; i++)
        {
            if (igralec.getGlobalBound(nasVec[i])) {
                zakljuci(okno, 1);
            }
        }

        okno.clear();

        dMet1.upodobi(okno);
        okno.draw(t_stMet);
        dMet2.upodobi(okno);
        igralec.upodobi(okno);

        okno.display();
    }

	return 0;
}