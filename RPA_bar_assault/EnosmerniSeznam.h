#pragma once

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>

template<class T>
class EnosmerniSeznam
{
    T* start;

public:
    EnosmerniSeznam()
    {
        this->start = NULL;
    }

    ~EnosmerniSeznam()
    {
        cisti();
    }

    T* getStart()
    {
        return start;
    }

    int vel()
    {
        int n = 0;
        if (start->nasl != NULL) n++;
        T* tmp = start;
        while (tmp->nasl != NULL)
        {
            tmp = tmp->nasl;
            n++;
        }
        return n;
    }

    T* getT(T* tmp, int n)
    {
        if (tmp != NULL)
        {
            if (tmp->indeks == n) return tmp;
            getT(tmp->nasl, n);
        }
    }

    void push(int n)
    {
        T* nov = new T;
        nov->indeks = n;
        nov->nasl = NULL;
        if (start != NULL)
        {
            T* tmp = start;
            while (tmp->nasl != NULL)
                tmp = tmp->nasl;
            tmp->nasl = nov;
        }
        else { if (start == NULL) start = nov; }
    }

    void pop(int n)
    {
        T* tmp = start;
        if (start != NULL)
        {
            if (start->indeks == n)
            {
                start = start->nasl;
                delete tmp;
                T* st = start;
                while (st->nasl != NULL)
                {
                    st->indeks--;
                    st = st->nasl;
                }
            }
            else
            {
                T* tmp1 = NULL;
                while (tmp->indeks != n)
                {
                    tmp1 = tmp;
                    tmp = tmp->nasl;
                }
                T* st = tmp;
                while (st->nasl != NULL)
                {
                    st->indeks--;
                    st = st->nasl;
                }
                tmp1->nasl = tmp->nasl;
                delete tmp;
            }
        }
        return;
    }

    void cisti()
    {
        if (start != NULL)
        {
            T* tmp = start, * tmp1 = NULL;
            while (tmp->nasl != NULL)
            {
                tmp1 = tmp->nasl;
                delete tmp;
                tmp = tmp1;
            }
            delete tmp;
        }
    }

    void izpis()
    {
        T * tmp = start;
        while (tmp->nasl != NULL)
        {
            std::cout << tmp->indeks << std::endl;
            tmp = tmp->nasl;
        }
    }
};

