#include <iostream>
#include <string>
#include "PigLatin.h"
using namespace std;

// A pig latin translator with rules : a) if the word starts with a vowel, append 'hay' at the end of the word
// b) otherwise, all the consonants from the start of the word are rotated to the end and 'ay' is appended
int main() {
	string english, pLatin;
	int i = 0;
	char yn;

	do {

		cout << "Enter a sentence : \n";
		getline(cin, english);
		cout << endl;

		goThroughEnglish(english, pLatin, i);

		cout << "Pig Latin: \n";
		cout << pLatin << endl;
		cout << endl;
		cout << "Enter another sentence? (y/n): ";
		cin >> yn;

		//english.clear();
		pLatin.clear();
		cin.get();
		i = 0;

	} while (tolower(yn) == 'y');

}