#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s);
    bool repeatedSubstringPattern2(string s);
};

int main(void) {
	Solution solution;
	string input = "abcaaabcaa";
	string input2 = "aba";
	bool ans = solution.repeatedSubstringPattern2(input);
	cout << "ans: " << ans << endl;
}

// Possible solutions
// 1. https://leetcode.com/problems/repeated-substring-pattern/discuss/1240684/Python-3-Simple-Solution-or-Single-pass-or-Only-few-lines
bool Solution::repeatedSubstringPattern(string s) {
	string repeatedString = "", memo = "";

	for (char c: s) {
		repeatedString = "";
		memo += c;
		if (s.length() == memo.length() || memo.length() * 2 > s.length()) continue;
		if (s.length() % memo.length() == 0) {
			int repeatedNum = s.length() / memo.length();
			while (repeatedNum > 0) {
				repeatedString += memo;
				repeatedNum--;
			}
			if (repeatedString == s) return true;
		}
	}

	return false;	
}

// 2. Using KMP algorithm
bool Solution::repeatedSubstringPattern2(string s) {

	// WIP
	return true;
}
