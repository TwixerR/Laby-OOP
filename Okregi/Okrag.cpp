#include "Okrag.h"

Okrag::Okrag(double radx, point center)
{
    this->radx = radx;
    this->center.x = center.x;
    this->center.y = center.y;
    count++;
}

Okrag::~Okrag()
{
    count--;
}

int Okrag::getOkragCount()
{
    return Okrag::count;
}

point Okrag::getCenter()
{
    return this->center;
}

double Okrag::getRadx()
{
    return this->radx;
}

double Okrag::getDist(Okrag a)
{
    return Odcinek::length(this->getCenter(), a.getCenter());
}


int Okrag::count = 0;
