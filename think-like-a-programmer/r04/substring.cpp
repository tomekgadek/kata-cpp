/*
	substring.cpp: Implementacja wlasnej funkcji substring.

	Dla dynamicznie przydzielanych łańcuchów stwórz funkcję 'substring', z
	następującymi trzema parametrami: zmienną typu 'arrayString', liczbą
	całkowitą oznaczającą początkową pozycję, liczbą całkowitą określającą
	długość łańcucha. Funkcja powinna zwrócić wskaźnik do nowo przydzielonego
	bloku pamięci zawierającego tablicę znaków. Musi ona zawierać znaki 
	pochodzące z oryginalnego łańcucha, poczynając od określonej pozycji i o
	podanej długości. Pierwotny łańcuch nie powinien zostać zmodyfikowany.
	Jeśli, więc oryginalnym łańcuchem był "abcdefg", pozycją początkowoą 3, a
	długość 4, wówczas nowy łańcuch powinien być równy "cdef".
*/
#include <iostream>

using namespace std;

typedef char * arrayString;

arrayString substring(arrayString s, int position, int size);

int main(void) {
	const int sizeSubstring = 4;
	const int startPosition = 3;
	arrayString testArray = new char[8];

	testArray[0] = 'a';
	testArray[1] = 'b';
	testArray[2] = 'c';
	testArray[3] = 'd';
	testArray[4] = 'e';
	testArray[5] = 'f';
	testArray[6] = 'g';
	testArray[7] = 0;
	
	arrayString result = substring(testArray, startPosition, sizeSubstring);
	
	cout << "\nString: " << testArray << " zawiera wyraz: " << result << endl;
	
	delete[] testArray;
	delete[] result;

	return 0;
}

arrayString substring(arrayString s, int position, int size) {
	arrayString newArray = new char[size + 1];
	
	for(int i = 0; i < size; i++) {
		newArray[i] = s[position - 1 + i];
	}
	newArray[size] = 0;
	
	return newArray;
}
