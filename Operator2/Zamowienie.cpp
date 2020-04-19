#include "Zamowienie.h"

#define LIMIT 10

unsigned int Zamowienie::getNextId()
{
	return count++;
}

Zamowienie::Zamowienie()
{
	this->id = getNextId();
	this->produkty = (Produkt*)malloc(LIMIT*sizeof(Produkt));
	this->produkty_count = 0;
}

Zamowienie::~Zamowienie()
{
	for (int i = this->produkty_count - 1; i >= 0; i--)
	{
		//POSSIBLE BUG DUE TO DELETE NULLPTR
		//delete &produkty[i];
	}
}

void Zamowienie::printProdukty()
{
	for (int i = 0; i < LIMIT; i++)
	{

		produkty[i].printInfo();
	}
}

Zamowienie& Zamowienie::operator+=(Produkt& prod)
{
	produkty[count++] = prod;
	return *this;
}

unsigned int Zamowienie::count = 0;
