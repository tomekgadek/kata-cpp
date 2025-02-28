/*
	rysunek1.cpp: Rezultat działania programu.

	#
	##
	###
	####
	###
	##
	#
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	for(int row = 1; row <= 8; row++) {

		for(int i = 1; i < 5 - abs(5 - row); i++) {

			cout << "#";
		}

		cout << "\n";
	}

	cout << endl;
	return 0;
}
