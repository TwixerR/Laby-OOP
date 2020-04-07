#include "Celsius.h"

Celsius::Celsius()
{
	//no suitable initial value
	this->val = -273.15;
}


Celsius::Celsius(double var) : val(var)
{

}

Celsius::~Celsius()
{
}

Celsius::operator double()
{
	return this->val-273.15;
}

Celsius::operator Kelvin()
{
	return Kelvin(this->val + 273.15);
}



Celsius Celsius::operator+(Celsius& obj)
{
	return Celsius(this->val + obj.val);
}

Celsius Celsius::operator+(Kelvin& obj)
{
	return Celsius(this->val + Celsius(obj).val);
}

Celsius Celsius::operator-(Celsius& obj)
{
	return Celsius(val + obj.val);
}

Celsius Celsius::operator-(Kelvin& obj)
{
	return Celsius(val - Celsius(obj).val);
}

Celsius& Celsius::operator=(Celsius& obj)
{
	this->val = obj.val;
	return *this;
}

Celsius& Celsius::operator=(Kelvin& obj)
{
	this->val = Celsius(obj).val;
	return *this;
}

std::istream& operator>>(std::istream& is, const Celsius& cel)
{
	is >> cel.val;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Celsius& cel)
{
	os << cel.val << 'C';
	return os;
}
