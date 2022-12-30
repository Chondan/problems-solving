#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/* 
Given an array of strings 'words' where each word 
can be written as a concatenation of the Morse code 
of each letter.

Return the number of different "transformations" 
among all words we have.
*/
class Solution {
private:
	string morseCodes[26] = {
		".-","-...","-.-.","-..",".","..-.","--.",
		"....","..",".---","-.-",".-..","--","-.",
		"---",".--.","--.-",".-.","...","-","..-",
		"...-",".--","-..-","-.--","--.."
	};

	int numberOfUniqueCode = 0;
	unordered_map<string, int> frequency;

	unordered_set<string> frequency2;

	int getMorseCodeIndex(char c);
	string getMorseCodeFromWord(string word);
public:
	int uniqueMorseRepresentations(vector<string> &words);
	int simpleUniqueMorseRepresentations(vector<string> &words);
};

int main(void) {
	Solution *solution = new Solution();

	vector<string> words = {"gin","zen","gig","msg"};	

	int numberOfUniqueCode1 = solution->uniqueMorseRepresentations(words);
	cout << "numberOfUniqueCode1: " << numberOfUniqueCode1 << endl;

	int numberOfUniqueCode2 = solution->simpleUniqueMorseRepresentations(words);
	cout << "numberOfUniqueCode2: " << numberOfUniqueCode2 << endl;
}

int Solution::uniqueMorseRepresentations(vector<string> &words) {
	for (string word: words) {
		string code = this->getMorseCodeFromWord(word);

		bool isNewMorseCode = frequency[code] == 0;
		this->numberOfUniqueCode = isNewMorseCode ? this->numberOfUniqueCode + 1 : this->numberOfUniqueCode;

		frequency[code] = frequency[code] + 1;
	}

	return this->numberOfUniqueCode;
}

int Solution::getMorseCodeIndex(char c) {
	/* 
		ASCII: a = 97, z = 122
		Index = ASCII - 97
	*/
	return (int)c - 97;
}

int Solution::simpleUniqueMorseRepresentations(vector<string> &words) {
	for (string word: words) {
		string code = this->getMorseCodeFromWord(word);
		frequency2.insert(code);
	}

	return frequency2.size();
}

string Solution::getMorseCodeFromWord(string word) {
	string code = "";

	for (char c: word) {
		string morseCode = this->morseCodes[this->getMorseCodeIndex(c)];
		code += morseCode;
	}

	return code;
}