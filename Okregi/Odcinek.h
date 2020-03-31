#pragma once

#include "structs.h"

class Odcinek
{
	point a;
	point b;
public:
	Odcinek(point a, point b);
	double length();
	static double length(point a, point b);
};

