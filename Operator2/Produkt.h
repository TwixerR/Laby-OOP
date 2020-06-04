#pragma once

#include <string>

class Produkt
{
	std::string nazwa;
	double cena;
public:
	Produkt();
	Produkt(Produkt& obj);
	Produkt(std::string anzwa, double cena);
	~Produkt();
	void printInfo();
	bool operator==(Produkt& prod);
	bool operator==(void* ptr);
	bool operator!=(Produkt& prod);
	bool isempty();
};

