/*
	studenciSortowanie.cpp: Kwartyle ocen studentów.

	Napisz program, który przetwarza tablicę obiektów 'student' oraz wyznacza
	kwartyle ocen, to znaczy ocenę, jaka byłaby wymagana, by być równym lub
	lepszym od 25%, 50% i 75% studentów.

	!Komentarz: Na ten moment rozwiązanie nie spełnia wymagań. Jedynie
	sortujemy dane. Kwartyle nie zostały jeszcze zaimplementowane!
*/

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

struct student {
	int grade;
	int studentId;
	string name;
};

int compareIds(const void *voidA, const void *voidB);
int compareRate(const void *voidA, const void *voidB);
void printStudents(const student *stud, int size);

int main(void) {
	const int ARRAY_SIZE = 10;

	student studentArray[ARRAY_SIZE] = {
		{87, 10001, "Krzysztof"},
		{28, 10002, "Bernard"},
		{100, 10003, "Wojciech"},
		{78, 10004, "Robert"},
		{84, 10005, "Bogdan"},
		{98, 10006, "Bozena"},
		{75, 10007, "Edyta"},
		{70, 10008, "Beata"},
		{81, 10009, "Alicja"},
		{68, 10010, "Joanna"}
	};

	printStudents(&studentArray[0], ARRAY_SIZE);
	qsort(studentArray, ARRAY_SIZE, sizeof(student), compareRate);
	printStudents(&studentArray[0], ARRAY_SIZE);
	qsort(studentArray, ARRAY_SIZE, sizeof(student), compareIds);
	printStudents(&studentArray[0], ARRAY_SIZE);

	return 0;
}

/* sortowanie listy studentow po identyfikatorach */
int compareIds(const void *voidA, const void *voidB) {
	student *studA = (student *)(voidA);
	student *studB = (student *)(voidB);
	
	return (studA->studentId) - (studB->studentId);
}

/* sortowanie listy studentow po otrzymanych ocenach */
int compareRate(const void *voidA, const void *voidB) {
	student *studA = (student *)(voidA);
	student *studB = (student *)(voidB);
	
	return (studA->grade) - (studB->grade);
}

/* wyswietlenie aktualnej listy studentow */
void printStudents(const student *stud, int size) {
	cout << endl;

	for(int i = 0; i < size; i++,  stud++) {
		cout << stud->grade << "\t" << stud->studentId << "\t" << stud->name;
		cout << endl;
	}
}

