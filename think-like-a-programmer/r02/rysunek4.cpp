/*
	rysunek4.cpp: Doniczka.

	########
	 ######
	  ####
	   ##
*/

#include <iostream>

using namespace std;

int main(void) {

	int cols = 8;
	for(int i = 0; i < cols; i++, cols -= 1) {

		for(int j = 0; j < i; j++) {
			cout << " ";
		}

		for(int j = i; j < cols; j++) {
			cout << "#";
		}
		cout << "\n";
	}

	cout << endl;
	return 0;
}
