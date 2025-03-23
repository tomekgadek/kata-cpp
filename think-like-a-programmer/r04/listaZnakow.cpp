/*
	Funkcje append oraz characterAt na liscie jednokierunkowej.

	Dodaj opis. Cwiczenie 4.4
*/
#include <iostream>

using namespace std;

struct listNode {
	char value;
	
	listNode *next;
};

typedef listNode * stringCollection;

void addRecord(stringCollection &sc, char ch);
void printRecord(stringCollection sc);
void removeList(stringCollection &sc);
char characterAt(stringCollection sc, int position);

int main(void) {
	stringCollection sc = NULL;

	addRecord(sc, 't');
	addRecord(sc, 'o');
	addRecord(sc, 'm');
	addRecord(sc, 'e');
	addRecord(sc, 'k');	
	addRecord(sc, '!');
	addRecord(sc, 's');
	addRecord(sc, 'u');
	addRecord(sc, 'p');
	addRecord(sc, 'e');
	addRecord(sc, 'r');
	
	printRecord(sc);
	
	cout << "Znak o numerze 0 to: " << characterAt(sc, 0) << "\n";
	cout << "Znak o numerze 5 to: " << characterAt(sc, 5) << "\n";
	cout << "Znak o numerze 10 to: " << characterAt(sc, 10) << "\n";
	cout << "Znak o numerze 11 to: " << characterAt(sc, 11) << "\n";
	
	removeList(sc);
	return 0;
}

void addRecord(stringCollection &sc, char ch) {
	listNode *newNode = new listNode;
	newNode->value = ch;

	if(sc == NULL) {
		newNode->next = sc;
		sc = newNode;
	} else {
		listNode *loopPtr = sc;
		listNode *beforePtr = sc;

		while(loopPtr != NULL) {
			beforePtr = loopPtr;	
			loopPtr = loopPtr->next;
		}
		
		beforePtr->next = newNode;
		beforePtr = beforePtr->next;
		beforePtr->next = NULL;
	}
}

void printRecord(stringCollection sc) {
	listNode *loopPtr = sc;

	while(loopPtr != NULL) {
		cout << loopPtr->value;
		
		loopPtr = loopPtr->next;
	}
	
	cout << endl;
}

void removeList(stringCollection &sc) {
	listNode *loopPtr = sc;
	
	while(loopPtr != NULL) {
		listNode *nextElement = loopPtr->next;
		delete loopPtr;
		sc = nextElement;

		loopPtr = sc;
	}
}

char characterAt(stringCollection sc, int position) {
	listNode *loopPtr = sc;

	for(int i = 0; loopPtr != NULL; i++) {
		if(i == position) {
			return loopPtr->value;
		}
		
		loopPtr = loopPtr->next;
	}

	return ' ';	// zwracam spacje w przypadku wystapienia bledu
}

