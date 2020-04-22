#include <iostream>

#include "Produkt.h"
#include "Zamowienie.h"

int main()
{
    std::cout << "Drugie laby z przełądowań operatorów\n";
    //stwórprodukt
    Produkt prod;
    prod.printInfo();  
    //stwórz tablicę produktów
    Produkt tab_prod[3];
    //i uzupełnij ją
    tab_prod[0] = Produkt("aaa", 123);
    tab_prod[1] = Produkt("bbb", 456);
    tab_prod[2] = Produkt("ccc", 789);
    //stwóz puste zamówienie
    Zamowienie zam1;
    zam1.printProdukty();
    //dodaj elementy
    std::cout << std::endl;
    for (int i = 3 - 1; i >= 0; i--)
    {
        zam1 += tab_prod[i];    
    }
    zam1.printProdukty();
    Zamowienie zam2(zam1);
    std::cout << "equality ";
    (zam2 == zam1) ? std::cout << "true\n" : std::cout << "false\n  ";

    --zam2;
    std::cout << "equality ";
    (zam2 == zam1) ? std::cout << "true\n" : std::cout << "false\n  ";

    zam1.printVerbose();
    zam2.printVerbose();
    
    return 0;
}