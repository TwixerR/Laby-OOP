#include <iostream>
#include "Celsius.h"
#include "Kelvin.h"

using namespace std;

int main() {
	Celsius a(10);
	Celsius s(20);
	Kelvin k(100);
	cout << "a(10C) + s(20C) = " << a + s << endl;
	cout << "a(10C) + k(100K) = " << a + k << endl << endl;
	//loop
	double q, w;
	char z, x, in = 'a';
	cout << "obliczenia w Kelvinach, sens nieistotny" << endl;
	cout << "przykładowy format: 100 C + 200 K" << endl;
	while (in != 0) {
		cout << "podaj temperatury i operację na nich" << endl;
		cin >> q >> z >> in >> w >> x;
		Kelvin kvar1(q);
		Kelvin kvar2(w);
		if (z == 'c' || z == 'C')
			kvar1 = Celsius(q);
		if (x == 'c' || x == 'C')
			kvar2 = Celsius(w);
		if (in == '+') {
			cout << kvar1 + kvar2 << endl;
		}else 
		if (in == '-') {
			cout << kvar1 - kvar2 << endl;
		}
	}
	
}
