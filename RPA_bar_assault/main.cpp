#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iostream>

/*
sfml-graphics-d.lib
sfml-audio-d.lib
sfml-network-d.lib
sfml-window-d.lib
sfml-system-d.lib
*/

#include "EnosmerniSeznam.h"
#include "Igralec.h"
#include "Nasprotnik.h"
#include "Drop_metek.h"
#include "Izstr_metek.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
//#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>

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
    srand(time(NULL));

    //Spremenljivke igre
    bool aliStrela = 0;
    int stNas = 2;
    int stim = 0;
    int stMet = 0;
    const float hit = 6.0f;
    int stdm = 2;//Stevilo nabojev, ki jih igrallec lahko nabere v igri
    sf::Event Event;

    EnosmerniSeznam<Drop_metek> dSez;
    EnosmerniSeznam<Izstr_metek> iSez;
    EnosmerniSeznam<Nasprotnik> nSez;

    sf::RenderWindow okno;
    sf::Vector2i pozOkna((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    okno.create(sf::VideoMode(900, 500), "Barbarian assault!", sf::Style::Titlebar | sf::Style::Close);
    okno.setPosition(pozOkna);
    okno.setKeyRepeatEnabled(true);
    
    Igralec igralec({ 40, 40 });
    igralec.setPoz({ rand() % okno.getSize().x - 30.0f + 1.0f, rand() % okno.getSize().y - 30.0f + 1.0f });

    for (int i = 0; i < stdm; i++)
    {
        dSez.push(i);
        dSez.getT(dSez.getStart(), i)->setPoz({ rand() % okno.getSize().x - 30.0f + 1.0f, rand() % okno.getSize().y - 30.0f + 1.0f });
    }
    
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    std::ostringstream s_stMet;
    s_stMet << "stMet: " << stMet%2;

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
            1. Dodamo nove nasprotnike glede na stevilo ubitih, vsak ubit nasprotnik
               poveèa stNas in za vsakega drugega ustreljenega se pojavi novi nasprotnik
               na ekranu.
        
            2. Preverjamo ali je v stiku z igralcem, nasprotnikom,...

            3. TODO: Sistem za nasprotnike(opravljeno)
        */   

        /////Preverjamo ali je igralec streljal, èe je potem ustvarimo novi objekt
        /////in preverjamo ali je kaj zadel, èe zadane nasprotnika poveèamo števec stNas,
        ///// za vsak drugi zadet nasprotnik se bo v igri pojavil še eden nasprotnik.
        
        okno.clear();
        
        if (aliStrela == true) {
            if (stMet > 0)
            {
                iSez.push(stim);
                iSez.getT(iSez.getStart(),stim)->setPoz(sf::Vector2f(igralec.getX(), igralec.getY() + 10.0f));
                stim++;
                stMet--;
                s_stMet.str("");
                s_stMet << "stMet " << stMet;
                t_stMet.setString(s_stMet.str());

            }
            aliStrela = false;
        }

        for (int i = 0; i < stim; i++)
        {
            for (int j = 0; j < stNas; j++)
            {
                if (nSez.getT(nSez.getStart(), j)->getGlobalBounds<Izstr_metek>(iSez.getT(iSez.getStart(), i)))
                {
                    nSez.getT(nSez.getStart(), j)->setPoz({ rand() % okno.getSize().x - 30.0f + 1.0f, rand() % okno.getSize().y - 30.0f + 1.0f });
                    stNas++;
                    iSez.pop(i);
                    stim--;

                }
            }
            if (iSez.getT(iSez.getStart(), i)->aliStikEkran(okno))
            {
                iSez.pop(i);
                stim--;
            }
            else
            {
                iSez.getT(iSez.getStart(), i)->premikStrel(0.5f);
                iSez.getT(iSez.getStart(), i)->upodobi(okno);
            }
        }

        std::cout << Nasprotnik::getKol() << std::endl;

        for (int i = Nasprotnik::getKol(); i < stNas / 2; i++)
        {
            nSez.push(Nasprotnik::getKol());
            nSez.getT(nSez.getStart(), Nasprotnik::getKol())->setPoz({ rand() % okno.getSize().x - 30.0f + 1.0f, rand() % okno.getSize().y - 30.0f + 1.0f });
            Nasprotnik::setKol(Nasprotnik::getKol() + 1);
        }

        /////Preverjamo ali je igralec blizu naboja, pristejemo k stevcu stMet,
        /////to pomeni, da lahko za toliko vec strelja.
        for (int i = 0; i < stdm; i++) {
            if (igralec.getGlobalBounds<Drop_metek>(dSez.getT(dSez.getStart(), i))) {
                dSez.getT(dSez.getStart(), i)->setPoz({ rand() % okno.getSize().x - 30.0f + 1.0f, rand() % okno.getSize().y - 30.0f + 1.0f });
                stMet++;
                s_stMet.str("");
                s_stMet << "stMet " << stMet;
                t_stMet.setString(s_stMet.str());
            }
        }
        
        /////preverja ali je igralec v stiku z nasprotnikom,
        /////ker znas samo streljati na daleè te z lahkoto premaga nasprotnik.
        for (int i = 0; i < stNas/2; i++)
        {
            if (igralec.getGlobalBounds<Nasprotnik>(nSez.getT(nSez.getStart(), i))) {
                zakljuci(okno, 1);
            }
        }

        for (int i = 0; i < stNas/2; i++)
            nSez.getT(nSez.getStart(), i)->upodobi(okno);
        for (int i = 0; i < stdm; i++)
            dSez.getT(dSez.getStart(), i)->upodobi(okno);
        
        okno.draw(t_stMet);
        igralec.upodobi(okno);

        okno.display();
    }

	return 0;
}