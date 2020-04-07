#pragma once
#include "Kelvin.h"
#include <iostream>

class Kelvin;
class Celsius
{
	double val;
public:
	Celsius();
	Celsius(double var);
	~Celsius();
	// conversion function
	explicit operator double();
	operator Kelvin();
	// I/O functions
	friend std::istream& operator>>(std::istream& is, const Celsius& cel);
	friend std::ostream& operator<<(std::ostream& os, const Celsius& cel);
	//arithmetic operators
	Celsius operator+ (Celsius& obj);
	Celsius operator+ (Kelvin& obj);
	Celsius operator- (Celsius& obj);
	Celsius operator- (Kelvin& obj);
	Celsius& operator= (Celsius& obj);
	Celsius& operator= (Kelvin& obj);
};

