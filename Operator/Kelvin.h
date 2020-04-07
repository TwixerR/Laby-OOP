#pragma once
#include "Celsius.h"
#include <iostream>

class Celsius;
class Kelvin
{
	double val;
public:
	Kelvin();
	Kelvin(double var);
	~Kelvin();
	//conversion function
	explicit operator double();
	operator Celsius();
	// I/O functions
	friend std::istream& operator>>(std::istream& is, const Kelvin& kel);
	friend std::ostream& operator<<(std::ostream& os, const Kelvin& kel);
	//arithmetic operators
	Kelvin operator+ (Kelvin& obj);
	Kelvin operator- (Kelvin& obj);
	Kelvin& operator= (Kelvin& obj);
	Kelvin operator+ (Celsius& obj);
	Kelvin operator- (Celsius& obj);
	Kelvin& operator= (Celsius& obj);
};

