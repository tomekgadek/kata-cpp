/*
	replaceString.cpp: Implementacja własnej funkcji replaceString.

	target:      ab
	replaceText: xyz
	source:      abcdeabee

	wynik:       xyzcdexyzee

	Dla naszych dynamicznie przydzielanych łańcuchów stwórz funkcję 
	'replaceString', która wykorzystuje trzy parametry, każdy o typie
	'arrayString': 'source', 'target' i 'replaceText'. Funkcja zamienia każde
	wystąpienie łańcucha 'target' w łańcuchu 'source' łańcuchem 'replaceText'.
	Na przykład jeśli 'source' wskazuje tablicę zawierającą ciąg znaków
	'abcdabee', 'target' wskazuje 'ab', a 'replaceText' ciąg 'xyz', wówczas
	po zakończeniu funkcji parametr 'source' powinien wskazywać tablice
	zwierającą łańcuch 'xyzcdxyzee'.
*/
#include <iostream>

using namespace std;

typedef char * arrayString;

arrayString replaceString(arrayString source, arrayString target, arrayString replaceText);
int getSizeArray(arrayString source);
int countTargetInString(arrayString source, arrayString target);

int main(void) {
	int sizeSourceLocal = 9;
	arrayString sourceLocal = new char[sizeSourceLocal+1];
	sourceLocal[0] = 'a';
	sourceLocal[1] = 'b';
	sourceLocal[2] = 'c';
	sourceLocal[3] = 'd';
	sourceLocal[4] = 'e';
	sourceLocal[5] = 'a';
	sourceLocal[6] = 'b';
	sourceLocal[7] = 'e';
	sourceLocal[8] = 'e';
	sourceLocal[9] = 0;

	int sizeTargetLocal = 2;
	arrayString targetLocal = new char[sizeTargetLocal+1];
	targetLocal[0] = 'a';
	targetLocal[1] = 'b';
	targetLocal[2] = 0;

	int sizeReplaceTextLocal = 3;
	arrayString replaceTextLocal = new char[sizeReplaceTextLocal+1];
	replaceTextLocal[0] = 'x';
	replaceTextLocal[1] = 'y';
	replaceTextLocal[2] = 'z';
	replaceTextLocal[3] = 0;

	arrayString result = replaceString(sourceLocal, targetLocal, replaceTextLocal);

	cout << "Bylo: " << sourceLocal << endl;
	cout << "Jest: " << result << endl;

	delete[] sourceLocal;
	delete[] targetLocal;
	delete[] replaceTextLocal;
	delete[] result;

	return 0;
}

arrayString replaceString(arrayString source, arrayString target, arrayString replaceText) {
	int sizeSource = getSizeArray(source);	// wyliczam rozmiar zrodla
	int sizeTarget = getSizeArray(target);	// wyliczam rozmiar znakow ktore zamieniam
	int sizeReplaceText = getSizeArray(replaceText);	// wyliczam rozmiar znakow ktore maja zostac zamienione

	int countTarget = countTargetInString(source, target);	// wyliczam liczbe znakow ktore maja zostac zamienione

	int mainSize = sizeSource - (sizeTarget * countTarget) + (sizeReplaceText * countTarget) + 1;
	arrayString mainSource = new char[mainSize];

	int s = 0;
	for(int i = 0; i < getSizeArray(source); i++) {
		if(source[i] == target[0]) {
			bool isInsise = true;
			int ii = i;
			for(int j = 0; j < getSizeArray(target); j++, ii++) {
				if(source[ii] != target[j]) {
					isInsise = false;
					break;
				}
			}
			
			if(isInsise) {
				for(int j = 0; j < getSizeArray(replaceText); j++) {
					mainSource[s] = replaceText[j];
					s++;
				}
				
				i += (getSizeArray(target) - 1);
			} else {
				mainSource[s] = source[i];
				s++;
			}
		} else {
			mainSource[s] = source[i];
			s++;
		}
	}

	mainSource[mainSize] = 0;

	return mainSource;
}

int getSizeArray(arrayString source) {
	int sizeArray = 0;

	while(source[sizeArray]) {
		sizeArray++;
	}

	return sizeArray;
}

int countTargetInString(arrayString source, arrayString target) {
	int counter = 0;

	for(int i = 0; i < getSizeArray(source); i++) {
		if(source[i] == target[0]) {
			bool isInsise = true;
			for(int j = 0; j < getSizeArray(target); j++, i++) {
				if(source[i] != target[j]) {
					isInsise = false;
					break;
				}
			}
			
			if(isInsise) {
				counter++;
			}
		}
	}
	
	return counter;
}
