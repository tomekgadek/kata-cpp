/*
	dziesietne-na-binarne.cpp: Zamaina liczb dziesietnych na binarne.
*/

#include <iostream>

using std::cin;
using std::cout;

void changeDecimalToBinar(int decimal);

int main(void) {
	int decimal = 0;

	cout << "Podaj liczbe dziesetna: ";
	cin >> decimal;
	
	cout << "Liczba " << decimal << " w systemie binarnym to: ";
	changeDecimalToBinar(decimal);
	cout << "\n";

	return 0;
}

void changeDecimalToBinar(int decimal) {
	
	if(decimal > 1) {
		changeDecimalToBinar(decimal/2);
	}
	
	cout << decimal % 2;
}
