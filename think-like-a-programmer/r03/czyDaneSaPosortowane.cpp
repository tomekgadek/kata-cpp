/*
	czyDaneSaPosortowane.cpp: Funkcja, która weryfikuje czy dane są posortowane.

	Napisz funkcję typu bool, której parametrami są tablica oraz liczba jej
	elementów. Funkcja powinna ustalać, czy dane w tablicy są posortowane.
	Rozwiązanie powinno wymagać użycia tylko pojedynczej pętli!
*/

#include <iostream>

using std::cout;
using std::endl;

bool isSortedData(int *array, int size);

int main(void) {

	const int ARRAY_SIZE = 10;
	
	int arrayOne[ARRAY_SIZE]	=	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arrayTwo[ARRAY_SIZE]	=	{ 1, 2, 3, 5, 6, 7, 8, 10, 9, 8 };
	int arrayThree[ARRAY_SIZE]	=	{ 1, 2, 4, 3, 10, 9, 8, 7, 6, 5 };
	int arrayFour[ARRAY_SIZE]	=	{ 1, 2, 3, 4, 5, 6, 7, 8, 10, 9 };
	
	/* testy */
	cout << "Tablica 1(true) : " << isSortedData(arrayOne, ARRAY_SIZE) << endl;
	cout << "Tablica 2(false): " << isSortedData(arrayTwo, ARRAY_SIZE) << endl;
	cout << "Tablica 3(false): " << isSortedData(arrayThree, ARRAY_SIZE) << endl;
	cout << "Tablica 4(false): " << isSortedData(arrayFour, ARRAY_SIZE) << endl;

	return 0;
}

bool isSortedData(int *array, int size) {
	for(int i = 0; i < size-1; i++) {
		if(array[i] > array[i+1]) {
			return false;
		}
	}
	
	return true;
}
