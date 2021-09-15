#include <vector>
#include <iostream>
using namespace std;

vector<string> split(string str) {
	vector<string> result;

	int len = str.size();
	string word = "";
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			if (word == "") continue;

			result.push_back(word);
			word = "";
		} else {
			word += str[i];
		}
	}
	if (word != "") result.push_back(word);

	return result;
}

class Solution {
public:
	int lengthOfLastWord(string s);
};

int main(void) {
	Solution solution;

	int ans = solution.lengthOfLastWord(" ");
	cout << "ans: " << ans << endl;
}

int Solution::lengthOfLastWord(string s) {

	vector<string> splittedStr = split(s);
	return splittedStr.size() == 0 ? 0 : splittedStr[splittedStr.size() - 1].size();
}

