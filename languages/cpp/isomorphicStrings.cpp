#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t);
};

int main(void) {Solution solution;
	string s = "badc", t = "baba";
	bool ans = solution.isIsomorphic(s, t);
	cout << "ans: " << ans << endl;
}

bool Solution::isIsomorphic(string s, string t) {
	if (s.length() != t.length()) return false;

	unordered_map<char, char> memo;
	unordered_map<char, bool> valueMemo;
	for (int i = 0; i < s.length(); i++) {
		char cs = s[i], ct = t[i];
		if (memo.find(cs) == memo.end()) {
			if (valueMemo.find(ct) == valueMemo.end()) {
				memo[cs] = ct;
				valueMemo[ct] = true;
			} else {
				return false;
			}
		} else {
			if (memo[cs] != ct) return false;
		}
	}
	return true;
}