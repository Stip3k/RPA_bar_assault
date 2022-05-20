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
	T *start;

public:
	EnosmerniSeznam();
	~EnosmerniSeznam();

	int vel();
	T getT(int n);
	void push(int n);
	void pop(int n);

	void cisti();
	void izpis();
};

