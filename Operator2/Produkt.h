#pragma once

#include <string>

class Produkt
{
	std::string nazwa;
	double cena;
public:
	Produkt();
	Produkt(Produkt& obj);
	~Produkt();
	void printInfo();
};

