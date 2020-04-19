#include "Produkt.h"
#include <time.h>
#include <iostream>

Produkt::Produkt()
{
	srand(time(NULL));
	this->cena = (rand() % 100000) / 100.0;
	char nam [10];
	for (int i = 10 - 1; i >= 0; i--)
	{
		nam[i] = rand() % ('z' - 'a' - 1) + 'a';
	}
	nam[9] = '\0';
	this->nazwa = std::string(nam);
}

Produkt::Produkt(Produkt& obj)
{
	this->cena = obj.cena;
	this->nazwa = obj.nazwa;
}

Produkt::~Produkt()
{
}

void Produkt::printInfo()
{
	std::cout << "\tNazwa prod.: " << this->nazwa << ", cena: " << this->cena << "\n";
}
