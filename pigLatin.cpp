#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool vowelLetter(char in);
string createPigWord(string word, int vowelPosition, int wordLength);
void removePunc(string word, string &punc, int &wordLength);
void outputWord(string word, string punc, ofstream &out);

int main() {

	ifstream inFile;
	ofstream outFile;
	string word;

	inFile.open("english.txt");
	outFile.open("piglatin.txt");

	if (!inFile) {
		cout << "Unable to Find File.\n";
		return 1;
	}

	while (inFile >> word) {
		int wLength = word.length();
		string punc = "";

		//Check for punctuation?
		removePunc(word, punc, wLength);

		//Option 1
		if (vowelLetter(word[0])){
			outputWord(word, punc, outFile);
		}

		//Option 2 & 3
		else{
			bool containsVowel = false;
			string pigWord;
		
			for (int i = 1; i < wLength; i++){
				if (vowelLetter(word[i])) {
					pigWord = createPigWord(word, i, wLength);
					outputWord(pigWord, punc, outFile);

					containsVowel = true;
					break;
				}
			}
			if (containsVowel == false){
				outputWord(word, punc, outFile);
			}
		}
	}

	return 0;
}

void removePunc(string word, string &punc, int &wordLength) {
	if (ispunct(word[wordLength - 1])){
		punc.append(1, word[wordLength - 1]);
		wordLength--;
	}
}

bool vowelLetter(char in){
	switch (in){
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case'i':
	case'o':
	case'O':
	case'u':
	case'U':
		return true;
	default:
		return false;
		}
}

string createPigWord(string word, int vowelPosition, int wordLength) {
	bool wasUpper = false;
	string pigWord;

	if (isupper(word[0])){
		wasUpper = true;
		tolower(word[0]);
	}

	for (int i = vowelPosition; i < wordLength; i++){
		pigWord.append(1, word[i]);
	}
	for (int i = 0; i < vowelPosition; i++){
		pigWord.append(1, word[i]);
	}

	if (wasUpper){
		toupper(pigWord[0]);
	}

	return pigWord;
}

void outputWord(string word, string punc, ofstream &out) {
	out << word << "ay" << punc << " ";
}
