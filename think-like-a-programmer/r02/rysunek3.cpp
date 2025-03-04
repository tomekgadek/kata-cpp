/*
	rysunek3.cpp: Kwadrat.

	#######
	#######
	#######
	#######
	#######
	#######
	#######
*/

#include <iostream>

using namespace std;

int main(void) {

	for(int i = 1; i <= 7; i++) {
		for(int j = 0; j <= 7; j++) {
			cout << "#";
		}
		cout << "\n";
	}

	cout << endl;
	return 0;
}
