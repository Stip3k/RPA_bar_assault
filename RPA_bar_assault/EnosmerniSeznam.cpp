#include "EnosmerniSeznam.h"

template<class T>
EnosmerniSeznam<T>::EnosmerniSeznam()
{
	this->start = NULL;
}

template<class T>
EnosmerniSeznam<T>::~EnosmerniSeznam()
{
	cisti();
}

template<class T>
int EnosmerniSeznam<T>::vel()
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

template<class T>
T EnosmerniSeznam<T>::getT(int n)
{
	T* tmp = start;
	while (tmp->indeks != n)
		tmp = tmp->nasl;
	if (tmp->indeks == n) return tmp;
}

template<class T>
void EnosmerniSeznam<T>::push(int n)
{
	T* nov = new T;
	nov->indeks = n;
	if (start != NULL)
	{
		T* tmp = start;
		while (tmp->nasl != NULL)
			tmp = tmp->nasl;
		tmp->nasl = nov;
		nov->nasl = NULL;
	}
	else { if (start == NULL) start = nov; }
}

template<class T>
void EnosmerniSeznam<T>::pop(int n)
{
	T* tmp = start;
	if (start != NULL)
	{
		if (start->indeks == n)
		{
			start = start->nasl;
			delete tmp;
			return;
		}
		T* tmp1 = NULL;
		while (tmp->indeks != n)
		{
			tmp1 = tmp;
			tmp = tmp->nasl;
		}
		tmp1->nasl = tmp->nasl;
		delete tmp;
	}
	return;
}

template<class T>
void EnosmerniSeznam<T>::cisti()
{
	T* tmp = start, tmp1 = NULL;
	while (tmp->nasl != NULL)
	{
		tmp1 = tmp;
		tmp = tmp->nasl;
		delete tmp1;
	}
}

template<class T>
void EnosmerniSeznam<T>::izpis()
{
	T* tmp = start;
	while (tmp->nasl != NULL)
	{
		std::cout << tmp->indeks << std::endl;
		tmp = tmp->nasl;
	}
}