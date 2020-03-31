#pragma once

#include "structs.h"

#include "Odcinek.h"

class Okrag
{
    friend class Odcinek;
    friend double Odcinek::length();

    friend void print(Okrag &);

    static int count;
    double radx;
    point center;
public:
    Okrag(double radx, point center);
    ~Okrag();
    //getters
    static int getOkragCount();
    point getCenter();
    double getRadx();
    double getDist(Okrag a);
};