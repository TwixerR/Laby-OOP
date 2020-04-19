#pragma once

#include "Produkt.h"

class Zamowienie
{
	static unsigned int count;
	unsigned int id;
	Produkt* produkty;
	unsigned int  produkty_count;
	unsigned int getNextId();
public:
	Zamowienie();
	~Zamowienie();
	void printProdukty();
	Zamowienie& operator+=(Produkt& prod);
};

