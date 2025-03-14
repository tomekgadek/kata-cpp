/*
	dominanta.cpp: Funkcja, która wyznacza dominantę.

	Napisz program, który wczytuje tablicę liczb całkowitych i wyznacza z nich
	'dominantę', czyli wartość, która występuje w zbiorze najczęściej.
*/
#include <iostream>

using namespace std;

int getDominant(const int *values, int size);

int main(void) {
	int dataSize = 0;
	
	cout << "Podaj rozmiar danych: ";
	cin >> dataSize;
	
	int *data = new int[dataSize];
	for(int i = 0; i < dataSize; i++) {
		cout << "Liczba_" << i+1 << " = ";
		cin >> data[i];
	}
	
	int wynik = getDominant(data, dataSize);
	cout << endl << "Dominanta z podanego zbioru to: " << wynik << endl;
	
	return 0;
}

/* metoda wyznacza dominante z podanego zbioru */
int getDominant(const int *values, int size) {

	int *val = new int[size];
	for(int i = 0; i < size; i++) {
		val[i] = values[i];	// kopiowanie danych aby nie zepsuc oryginalu
	}
	
	// sortowanie danych
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size-1; j++) {
			if(val[j] > val[j+1]) {
				int temp = val[j];
				val[j] = val[j+1];
				val[j+1] = temp;
			}
		}
	}
	
	// wyszukiwanie dominanty
	int result = val[0];
	int counter = 1;
	int mainResult = val[0];
	int mainCounter = 1;

	for(int i = 1; i < size; i++) {
		if(result == val[i]) {
			counter++;
		}
		
		if(counter >= mainCounter) {
			mainCounter = counter;
			mainResult = val[i-1];

			counter = 1;
			result = val[i];
		}
	}

	delete[] val;

	if(mainCounter == 1) {
		printf("Brak dominanty. \n");
		exit(1);
	}

	return mainResult;
}
