#include "Zamowienie.h"
#include <iostream>

constexpr auto LIMIT = 10;

unsigned int Zamowienie::getNextId()
{
	return count++;
}

Zamowienie::Zamowienie()
{
	this->id = getNextId();
	this->produkty = new Produkt[LIMIT];
	//this->produkty = (Produkt*)malloc(LIMIT*sizeof(Produkt));
	this->produkty_count = 0;
}

Zamowienie::Zamowienie(Zamowienie& zam)
{
	this->id = getNextId();
	this->produkty = new Produkt[LIMIT];
	for (int i = zam.produkty_count - 1; i >= 0; i--)
	{
		this->produkty[i] = zam.produkty[i];
	}
	this->produkty_count = zam.produkty_count;
}

Zamowienie::~Zamowienie()
{

	//free(produkty);
}

void Zamowienie::printProdukty()
{
	for (int i = 0; i < LIMIT; i++)
	{

		produkty[i].printInfo();
	}
}

void Zamowienie::printVerbose()
{
	printf("id: %d, count: %d, prod_count: %d\n", this->id, this->produkty_count);
	printProdukty();
}

Zamowienie& Zamowienie::operator+=(Produkt& prod)
{
	this->produkty[this->produkty_count++] = prod;
	return *this;
}

Zamowienie& Zamowienie::operator-=(Produkt& prod)
{
	bool found = false;
	for (int i = 0; i < this->produkty_count; i++)
	{
		if (produkty[i] == prod) {
			found = true;
			this->produkty_count--;
			produkty[i] = Produkt("", 0.0);
			continue;
		}
		if (found) {
			produkty[i - 1] = produkty[i];
		}
	}
	return *this;
}

Zamowienie& Zamowienie::operator--()
{
	for (int i = 0; i < this->produkty_count-1; i++)
	{
		produkty[i] = produkty[i + 1];
	}
	this->produkty[produkty_count-1] = Produkt();
	--produkty_count;
	return *this;
}

Zamowienie Zamowienie::operator--(int ignore)
{
	this->produkty[--produkty_count] = Produkt();
	return *this;
}

bool Zamowienie::operator==(Zamowienie& zam)
{
	if (this->produkty_count != zam.produkty_count)
		return false;
	for (int i = produkty_count - 1; i >= 0; i--)
	{
		if (this->produkty[i] != zam.produkty[i])
			return false;
	}
	return true;
}

bool Zamowienie::operator!=(Zamowienie& zam)
{
	return false;
}

unsigned int Zamowienie::count = 0;
