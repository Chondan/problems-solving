#include <iostream>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k);
    string licenseKeyFormatting2(string s, int k);
};

int main(void) {
	Solution solution;
	string input = "5F3Z-2e-9-w";
	int k1 = 4;
	string input2 = "2-5g-3-J";
	int k2 = 2;
	string ans = solution.licenseKeyFormatting2(input2, k2);
	cout << "ans: " << ans << endl;
}

// Time exceed
string Solution::licenseKeyFormatting(string s, int k) {
	string ans = "";
	int count = 0;

	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '-') continue;

		char c = s[i];
		if (c >= 97 && c <= 122) c -= 32; 

		ans = c + ans;
		count++;

		if (count == k && i - 1 >= 0) {
			ans = '-' + ans;
			count = 0;
		}
	}

	if (ans[0] == '-') {
		ans = ans.substr(1);
	}

	return ans;
}

// Better solution faster than 83.40%
string Solution::licenseKeyFormatting2(string s, int k) {
	string ans, temp;
	int n = s.length();

	for (int i = 0; i < n; i++) {
		if (s[i] != '-') temp += s[i];
	}

	int j = temp.length() - 1;
	for (int i = 0; i < temp.length(); i++) {
		if (i % k == 0 && i >= k) ans += '-';
		ans += toupper(temp[j--]);
	}

	reverse(ans.begin(), ans.end());
	return ans;

}