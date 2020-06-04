#include <iostream>

/*
1.  Napisać program, w którym zostaną zaimplementowane 3 funkcje sortujące (algorytmem bąbelkowym, przez wstawianie oraz quicksort) z wykorzystaniem szablonów funkcji.
	Należy zaprezentować ich zastosowanie dla różnych rodzajów danych wejściowych. Funkcje powinny przyjmować jako parametr tablice do posortowania oraz liczbę elementów w tablicy.

2. Napisać program, w którym zostanie zaimplementowana klasa operująca na stosie z wykorzystaniem szablonów klas. Należy zaprezentować działanie tak stworzonego stosu dla różnych rodzajów danych wejściowych.

3. Napisać program, w którym zostanie zaimplementowana klasa operująca na liście z wykorzystaniem szablonów klas. Należy zaprezentować działanie tak stworzonej listy dla różnych rodzajów danych wejściowych. */

using namespace std;

template < class T >
inline void swapp(T& a, T& b) {
	T tmp(b);
	b = a;
	a = tmp;
}

template < class T >
T* bubblesort(T* arr, int len) {
	int min = 0;
	for (int i = 0; i < len; i++) {
		for (int k = len - 1; k >= i; k--) {
			if (arr[k - 1] > arr[k])
				swap(arr[k - 1], arr[k]);
		}
	}
	return arr;
}

template < class T >
T* insertionsort(T* arr, int len) {
	int min;
	if (len) {
		for (int left = 0; left < len; left++) {
			min = left;
			for (int i = left; i < len; i++) {
				if (arr[i] < arr[min])
					min = i;
			}
			swap(arr[left], arr[min]);
		}
	}
	return arr;
}

template < class T >
int partition(T arr[], int low, int high) {
	T pivot = arr[(low + high) / 2];
	int leftindex = low;
	int rightindex = high;

	while (1) {
		while (arr[leftindex] < pivot && leftindex < high) {
			leftindex++;
		}
		while (arr[rightindex] > pivot && rightindex > low) {
			rightindex--;
		}
		if (leftindex >= rightindex)
			return rightindex;
		swapp(arr[leftindex], arr[rightindex]);
		leftindex++;
		rightindex--;
	}
}

template < class T >
void _quicksort(T arr[], int low, int high) {
	if (low < high) {
		int part = partition(arr, low, high);
		_quicksort(arr, low, part);
		_quicksort(arr, part + 1, high);
	}
}

template < class T >
T* quicksort(T arr[], int len) {
	if (len > 0)
		_quicksort(arr, 0, len - 1);
	return arr;
}



template < class T >
void printarr(T* arr, int len) {
	if (len == 1) {
		cout << arr[0] << endl;
		return;
	}
	cout << "{" << arr[0];
	for (int i = 1; i < len; i++) {
		cout << " ," << arr[i];
	}
	printf("}");
}

int main() {
	{
		int arrayI[10] = { 1,17,456,7,213,-345,56,3346,76,23 };
		double arrayD[10] = { 0.3245, 345.5436,-345.567,45356.5633,12.00,34.56,67.12,568.34,0.0, 1.0 };
		char arrayC[10] = { 'a','z','d','c','h','g','f','z','s','w' };
		printarr(bubblesort(arrayI, 10), 10); cout << endl;
		printarr(bubblesort(arrayD, 10), 10); cout << endl;
		printarr(bubblesort(arrayC, 10), 10); cout << endl;
	}
	{
		int arrayI[10] = { 1,17,456,7,213,-345,56,3346,76,23 };
		double arrayD[10] = { 0.3245, 345.5436,-345.567,45356.5633,12.00,34.56,67.12,568.34,0.0, 1.0 };
		char arrayC[10] = { 'a','z','d','c','h','g','f','z','s','w' };
		printarr(insertionsort(arrayI, 10), 10); cout << endl;
		printarr(insertionsort(arrayD, 10), 10); cout << endl;
		printarr(insertionsort(arrayC, 10), 10); cout << endl;
	}
	{
		int arrayI[10] = { 1,17,456,7,213,-345,56,3346,76,23 };
		double arrayD[10] = { 0.3245, 345.5436,-345.567,45356.5633,12.00,34.56,67.12,568.34,0.0, 1.0 };
		char arrayC[10] = { 'a','z','d','c','h','g','f','z','s','w' };
		printarr(quicksort(arrayI, 10), 10); cout << endl;
		printarr(quicksort(arrayD, 10), 10); cout << endl;
		printarr(quicksort(arrayC, 10), 10); cout << endl;
	}

}