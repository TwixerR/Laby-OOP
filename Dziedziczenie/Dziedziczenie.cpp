#include <iostream>
#include <string>

using namespace std;

class Pracownik {
protected:
    int id;
    string imie;
    string nazwisko;
    static int licznik;
    static int licznik_id;
    unsigned int stawka = 10;
public:
    Pracownik() : imie("Jan"), nazwisko("Kowalski") {
        licznik++;
        id = ++licznik_id;
        cout << "Konstruktor domylny Pracownik()\n";
    }
    Pracownik(string imie, string nazwisko) : imie("Jan"), nazwisko("Kowalski") {
        licznik++;
        id = ++licznik_id;
        imie = imie;
        nazwisko = nazwisko;
        cout << "Konstruktor sparametryzowany Pracownik() \n\timie: " << imie << "\n\tnazwisko: " << nazwisko << endl;
    }
    ~Pracownik() {
        licznik--;
        cout << "Destruktor Pracownik()\n";
    }
    virtual void printinfo() {
        cout << "Pracownik " << imie << " " << nazwisko << ", stawka: " << stawka << endl;
    }
};

int Pracownik::licznik = 0;
int Pracownik::licznik_id = 0;

class Kierownik : public Pracownik {
    const int przelicznik = 5;
public:
    Kierownik() {

        cout << "Konstruktor domylny Kierownik()\n";
    }
    Kierownik(string imie, string nazwisko) : Pracownik(imie, nazwisko){
        imie = imie;
        nazwisko = nazwisko;
        cout << "Konstruktor sparametryzowany Kierownik() \n\timie: " << imie << "\n\tnazwisko: " << nazwisko << endl;
    }
    ~Kierownik() {

        cout << "Destruktor Kierownik()\n";
    }
    void printinfo() {
        cout << "Kierownik " << imie << " " << nazwisko << ", stawka: " << stawka*przelicznik << endl;
    }
};

class Informatyk : public Pracownik {
    const int przelicznik = 3.5;
public:
    Informatyk() {
        cout << "Konstruktor domyślny Informatyk()\n";
    }
    Informatyk(Informatyk& inf) {
        imie = inf.imie;
        nazwisko = inf.nazwisko;

        cout << "Konstruktor kopiujący Informatyk()\n";
    }
    ~Informatyk() {
        cout << "Destruktor Informatyk()\n";
    }
    void printinfo() {
        cout << "Informatyk " << imie << " " << nazwisko << ", stawka: " << stawka*przelicznik << endl;
    }
};

int main(){
    string imie;
    string nazw;
    //domyślny praco
    Pracownik prac1;
    //sparametryzowany praco
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "i nazwisko: ";
    cin >> nazw;
    Pracownik prac2(imie, nazw);
    //domyślny infor
    Informatyk inf1;
    //kopia infor
    Informatyk inf2(inf1);
    //domyślny kier
    Kierownik kiero;

    Pracownik* zespół[3];
    zespół[0] = new Kierownik("Adam", "Sandler");
    zespół[1] = new Informatyk();
    zespół[2] = new Pracownik("wojciech", "Mann");
    zespół[0]->printinfo();
    zespół[1]->printinfo();
    zespół[2]->printinfo();

    delete zespół[0];
    delete zespół[1];
    delete zespół[2];
    return 0;
}