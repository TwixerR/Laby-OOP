#include <iostream>
#include <map>

#include "structs.h"

#include "Odcinek.h"
#include "Okrag.h"
#include <time.h>

#define SIZE 10
#define PRECISION 0.00001

using namespace std;

//further mapped
typedef enum {tożsame, wsp_srod, roz_wew, st_wew, st_zew, roz_zew, przec2} relacja;
std::map<relacja, string> alias;

void print(Okrag& a) {
    printf("OKR (x:%d,y:%d) r:%lf\n", a.center.x, a.center.y, a.radx);
};

relacja cięcie(Okrag a, Okrag b) {
    double arad = a.getRadx();
    double brad = b.getRadx();
    int ax = a.getCenter().x;
    int bx = b.getCenter().x;
    int ay = a.getCenter().y;
    int by = b.getCenter().y;
    double lgth = Odcinek::length(a.getCenter(), b.getCenter());
    //case tożsame
    if ((arad == brad || arad + PRECISION == brad || arad - PRECISION == brad) && ax == bx && ay == by)
        return tożsame;
    if (ax == bx && ay == by && arad != brad)
        return wsp_srod;
    if (lgth < abs(brad - arad))
        return roz_wew; 
    if (lgth > abs(brad + arad))
        return roz_wew;
    if (lgth == abs(brad - arad))
        return st_wew;
    if (lgth == brad + arad)
        return st_zew;
    
    return przec2;
};

inline void printCięcie(relacja rel) {
    cout << alias[rel] << endl;
    return;
}

int main() {
    //obligatory section
    srand(time(NULL));
    cout << "Hell'O Okregi!" << endl;

    //BEGIN fill map
    //stores aliases for different kinds of relacja. basically gets type name from declared enum relacja
    alias[tożsame] = "Tożsame";
    alias[wsp_srod] = "Współśrodkowe";
    alias[roz_wew] = "Rozłączne wewnętrznie";
    alias[st_wew] = "Styczne wewnętrznie";
    alias[st_zew] = "Styczne zewnętrznie";
    alias[roz_zew] = "Rozłączne zewnętrznie";
    alias[przec2] = "Przecinające się w dwóch punktach";
    //END fill map

    //BEGIN exercise
    Okrag one(10.0, { 0,0 });
    Okrag two(5.0, { 1,0 });
    print(one);
    print(two);
    printCięcie(cięcie(one, two));

    Okrag* arr1[SIZE];
    Okrag* arr2[SIZE];
    for (int i = SIZE - 1; i >= 0; i--)
    {
        //generate integral position for Okrag centers
        int randX_A = (rand() % 21) - 10;
        int randY_A = (rand() % 21) - 10;
        int randX_B = (rand() % 21) - 10;
        int randY_B = (rand() % 21) - 10;
        //generate radius [0-10] with 4 decimal positions
        double randRAD_A = (double)(rand() % 1000001) / 1000.0;
        double randRAD_B = (double)(rand() % 1000001) / 1000.0;
        //fill arrays
        arr1[i] = new Okrag(randRAD_A, { randX_A, randY_A });
        arr2[i] = new Okrag(randRAD_B, { randX_B, randY_B });
        //print created objects
        printf("arr1->");
        print(*arr1[i]);
        printf("arr2->");
        print(*arr2[i]);
        //print their relacja
        printCięcie(cięcie(*arr1[i], *arr2[i]));
        
    }

    //clean up
    for (int i = SIZE - 1; i >= 0; i--)
    {
        delete arr1[i];
        delete arr2[i];
    }
    //all else will self-destruct

    return 0;
}