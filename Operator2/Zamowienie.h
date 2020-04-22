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
	//construction site
	Zamowienie();
	Zamowienie(Zamowienie& zam);
	~Zamowienie();
	//operators
	Zamowienie& operator+=(Produkt& prod);
	Zamowienie& operator-=(Produkt& prod);
	Zamowienie& operator--();
	Zamowienie operator--(int ignore);	
	bool operator==(Zamowienie& zam);
	bool operator!=(Zamowienie& zam);
	//fluff
	void printProdukty();
	void printVerbose();
};

