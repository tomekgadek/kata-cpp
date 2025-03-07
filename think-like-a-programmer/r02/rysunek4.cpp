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

	int space_counter = 0;

	for(int cols = 8; cols > 0; cols -= 2) {

		for(int i = 0; i < space_counter; i++) {
			cout << " ";
		}

		for(int i = 0; i < cols; i++) {
			cout << "#";
		}

		space_counter++;

		cout << endl;
	}

	cout << endl;

	return 0;
}
