#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2);
};

int main(void) {
	Solution solution;

	string ans1 = solution.multiply("123", "456");
	cout << "ans: " << ans1 << endl;
}

// "123" x "456" 
// ans -> "000000"
// step1 -> 3 x 6 -> ans = "000018" (18)
// step2 -> 3 x 5 -> ans = "000168" (16)
// step3 -> 3 x 4 -> ans = "001368" (13)
// step4 -> 2 x 6 -> ans = "001488" (18)
// step5 -> 2 x 5
// step6 -> 2 x 4
// step7 -> 1 x 6
// step8 -> 1 x 5
// step9 -> 1 x 4
string Solution::multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0") {
		return "0";
	}

	int len1 = num1.length();
	int len2 = num2.length();
	string ans(len1+len2, '0'); // "00000..."

	for (int i = len1 - 1; i >= 0; i--) {
		for (int j = len2 - 1; j >= 0; j--) {
			int p = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
			ans[i + j + 1] = p % 10 + '0'; // store as a char e.g. "8" which equal to 56 in ascii
			ans[i + j] += p / 10;
		}
	}

	if (ans[0] == '0') {
		return ans.substr(1);
	}
	return ans;
}