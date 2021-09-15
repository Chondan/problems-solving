#include <iostream>
using namespace std;

bool isAlphanumeric(char c) {
	if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122) {
		return false;
	}
	return true;
}

class Solution {
public:
    bool isPalindrome(string s);
};

int main(void) {
	Solution solution;
	string input = "A man, a plan, a canal: Panama";
	bool ans = solution.isPalindrome(input);
	cout << "ans: " << ans << endl;
}

bool Solution::isPalindrome(string s) {
	if (s.size() == 1) return true;

	// ASCII
	// numeric: 48-57
	// alphabet: 65-90, 97-122	
	int l = 0;
	int r = s.size() - 1;
	bool ans = true;
	while (l < r) {
		if (!isAlphanumeric(s[l])) l++;
		if (!isAlphanumeric(s[r])) r--;

		// cout << isAlphanumeric(s[l]) << " " << isAlphanumeric(s[r]) << endl;
		if (isAlphanumeric(s[l]) && isAlphanumeric(s[r])) {
			// cout << s[l] << " " << s[r] << endl;
			if ((char)tolower(s[l]) != (char)tolower(s[r])) return false;
			l++;
			r--;
		}
		
	}
	return ans;
}