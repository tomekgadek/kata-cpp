/*
	rysunek2.cpp: Trojkat prostokatny.

	#######
	######
	#####
	####
	###
	##
	#
*/

#include <iostream>

using namespace std;

int main(void) {

	for(int i = 1; i <= 7; i++) {
		for(int j = i; j <= 7; j++) {
			cout << "#";
		}
		cout << "\n";
	}

	cout << endl;
	return 0;
}
