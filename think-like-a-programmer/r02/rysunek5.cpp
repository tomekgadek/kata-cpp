/*
	rysunek5.cpp: Karo.

	   ##
	  ####
	 ######
	########
	########
	 ######
	  ####
	   ##
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	int base = 0;
	
	cout << "Podaj dlugosc podstawy: ";
	cin >> base;
	
	int hash = (base % 2 == 0? 2 : 1);
	int whiteSpace = (base % 2 == 0? base/2-1 : base/2);
	
	// zmiana podstawy na pazysta w celu poprawnego generowania rysunku
	base += (base % 2 == 0? 0 : 1);

	for(int i = 1; i <= base; i++, --whiteSpace) {
		for(int j = 0; j < abs(whiteSpace); j++) {
			cout << " ";
		}

		for(int j = 0; j < hash; j++) {
			cout << "#";
		}
		
		cout << "\n";
		
		if(i == base/2 && whiteSpace == 0) {
			whiteSpace++;
			hash -= 2;
		}
		
		hash += (i <= base/2? 2 : -2);
	}

	return 0;
}

