/*
	dekodowanie-wiadomosci.cpp: Algorytm dekodowania zaszyfrowanej wiadomosci.

	Zakodowana wiadomosc:

	313,12312,906,3337,2529,568,1994,689,14994,221,216,11,599,18,11684,
	0,136,1496,27,10
*/

#include <iostream>

using std::cin;
using std::cout;

int main(void) {

	char outputCharacter;
	enum modeType {UPPERCASE, LOWERCASE, PUNCTATION};
	modeType mode = UPPERCASE;
	char digitChar;
	
	do {
		digitChar = cin.get();
		int number = (digitChar - '0');
		digitChar = cin.get();
		
		while((digitChar != 10) && (digitChar != ',')) {
			number = number * 10 + (digitChar - '0');
			digitChar = cin.get();
		}

		switch(mode) {
			case UPPERCASE:
				number = number % 27;
				outputCharacter = number + 'A' - 1;
				if(number == 0) {
					mode = LOWERCASE;
					continue;
				}
				break;
			case LOWERCASE:
				number = number % 27;
				outputCharacter = number + 'a' - 1;
				if(number == 0) {
					mode = PUNCTATION;
					continue;
				}
				break;
			case PUNCTATION:
				number = number % 9;
				switch(number) {
					case 1: outputCharacter = '!'; break;
					case 2: outputCharacter = '?'; break;
					case 3: outputCharacter = ','; break;
					case 4: outputCharacter = '.'; break;
					case 5: outputCharacter = ' '; break;
					case 6: outputCharacter = ';'; break;
					case 7: outputCharacter = '"'; break;
					case 8: outputCharacter = '\''; break;
				}
				if(number == 0) {
					mode = UPPERCASE;
					continue;
				}
				break;
		}
		cout << outputCharacter;
	} while(digitChar != 10);
	cout << "\n";

	return 0;
}
