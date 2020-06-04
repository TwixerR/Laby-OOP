#include "Produkt.h"
#include <iostream>

Produkt::Produkt() : nazwa(""), cena(0.0)
{
}

Produkt::Produkt(Produkt& obj)
{
	this->cena = obj.cena;
	this->nazwa = obj.nazwa;
}

Produkt::Produkt(std::string anzwa, double cena)
{
	this->nazwa = anzwa;
	this->cena = cena;
}

Produkt::~Produkt()
{
}

void Produkt::printInfo()
{
	std::cout << "\tNazwa prod.: " << this->nazwa << ", cena: " << this->cena << "\n";
}

bool Produkt::operator==(Produkt& prod)
{
	return (this->cena == prod.cena && this->nazwa == prod.nazwa);
}

bool Produkt::operator==(void* ptr)
{
	return this == nullptr;
}

bool Produkt::operator!=(Produkt& prod)
{
	return !(this->cena == prod.cena && this->nazwa == prod.nazwa);
}

bool Produkt::isempty()
{
	Produkt a;
	return (this->cena == a.cena && this->nazwa == a.nazwa);
}
