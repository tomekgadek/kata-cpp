/*
	algorytm-luhna.cpp: Generowanie sumy kontrolnej.

	TODO: Dopisac dokumentacje: Jak dziala algorytm i to dobrze wytlumaczyc.
*/

#include <iostream>

using std::cin;
using std::cout;

int doubleDigitValue(int);

int main(void) {

	char digit;
	int oddLengthChecksum = 0;
	int evenLangthChecksum = 0;
	int position = 1;

	cout << "Wprowadz liczbe: ";
	digit = cin.get();
	
	while(digit != 10) {
		if(position % 2 == 0) {
			oddLengthChecksum += doubleDigitValue(digit - '0');
			evenLangthChecksum += digit - '0';
		} else {
			oddLengthChecksum += digit - '0';
			evenLangthChecksum += doubleDigitValue(digit - '0');
		}
		digit = cin.get();
		position++;
	}

	int checksum;
	if((position - 1) % 2 == 0)
		checksum = evenLangthChecksum;
	else
		checksum = oddLengthChecksum;
	cout << "Suma kontrolna wynosi " << checksum << ". \n";
	if(checksum % 10 == 0)
		cout << "Suma kontrolna jest podzielna przez 10. Wynik poprawny. \n";
	else
		cout << "Suma kontrolna nie jest podzielna przez 10. Wynik niepoprawny. \n";

	return 0;
}

int doubleDigitValue(int digit) {

	int doubleDigit = digit * 2;
	int sum;
	
	if(doubleDigit >= 10)
		sum = 1 + doubleDigit % 10;
	else
		sum = doubleDigit;
	return sum;
}
