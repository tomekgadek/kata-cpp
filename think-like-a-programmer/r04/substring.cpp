/*
	substring.cpp: Implementacja wlasnej funckji substring.

	UWAGA! Dokończyć opis!
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
