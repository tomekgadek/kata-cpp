/*
	algorytm-luhna.cpp: Kontrola poprawności za pomocą sumy kontrolnej Luhna.

	Algorytm Luhna jest powszechnie używanym systemem służącym do 
	przeprowadzania kontroli poprawności numerów identyfikacyjnych.
	W numerze źródłowym weź pod uwagę co drugą cyfrę i pomnóż ją
	przez 2. Następnie dodaj wartości wszystkich cyfr (jeśli podwojona
	wartość składa się z dwóch cyfr, potraktuj je oddzielnie). Numer
	identyfikacyjny jest poprawny, jeśli suma jest podzielna przez 10.

	Napisz program, który odczytuje numer identyfikacyjny o dowolnej
	długości i przy użyciu algorytmu Luhna ustala, czy jest on poprawny.
	Program musi przetworzyć dany znak przed odczytaniem następnego.
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
