#include "Kelvin.h"
#include "Celsius.h"

Kelvin::Kelvin()
{
	//no suitable initial value
	this->val = 0;
}

Kelvin::Kelvin(double var)
{
	this->val = var;
}

Kelvin::~Kelvin()
{
}

Kelvin::operator double()
{
	return this->val;
}

Kelvin::operator Celsius()
{
	return Celsius(this->val - 273.15);
}


Kelvin Kelvin::operator+(Kelvin& obj)
{
	return Kelvin(this->val + obj.val);
}


Kelvin Kelvin::operator-(Kelvin& obj)
{
	return Kelvin(this->val - obj.val);
}

Kelvin& Kelvin::operator=(Kelvin& obj)
{
	this->val = obj.val;
	return *this;
}

Kelvin Kelvin::operator+(Celsius& obj)
{
	return Kelvin(this->val + Kelvin(obj).val);
}

Kelvin Kelvin::operator-(Celsius& obj)
{
	return Kelvin(this->val - Kelvin(obj).val);
}

Kelvin& Kelvin::operator=(Celsius& obj)
{
	this->val = Kelvin(obj).val;
	return *this;
}

std::istream& operator>>(std::istream& is, const Kelvin& kel)
{
	is >> kel.val;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Kelvin& kel)
{
	os << kel.val << 'K';
	return os;
}
