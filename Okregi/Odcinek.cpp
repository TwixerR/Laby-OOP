#include "Odcinek.h"
#include <cmath>

Odcinek::Odcinek(point a, point b)
{
	this->a = a;
	this->b = b;
}

double Odcinek::length()
{
	return sqrt(
		(this->b.x - this->a.x) * (this->b.x - this->a.x) +
		(this->b.y - this->a.y) * (this->b.y - this->a.y)
	);
}

double Odcinek::length(point a, point b)
{
	return sqrt(
		(b.x - a.x) * (b.x - a.x) +
		(b.y - a.y) * (b.y - a.y)
	);
}
