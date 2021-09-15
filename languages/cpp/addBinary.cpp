#include <iostream>
using namespace std;

string generateZero(int n) {
	string result = "";
	while (n > 0) {
		result += "0";
		n--;
	}
	return result;
}

class Solution {
public:
	string addBinary(string a, string b);
};

int main(void) {
	Solution solution;
	string ans = solution.addBinary("1111", "1111");
	cout << "ans: " << ans << endl;	
}

string Solution::addBinary(string a, string b) {

	int lenA = a.size();
	int lenB = b.size();
	int maxLen = max(lenA, lenB);

	// put zero in front of the shorter string
	if (lenA > lenB) {
		b = generateZero(lenA - lenB) + b;
	} else if (lenA < lenB) {
		a = generateZero(lenB - lenA) + a;
	}

	string sum = "";
	int memo = 0;
	for (int i = maxLen - 1; i >= 0; i--) {
		int numA = a[i] - '0';
		int numB = b[i] - '0';
		int sumNum = numA + numB + memo;
		switch (sumNum) {
			case 1:
			case 0: {
				char num = sumNum + '0';
				sum = num + sum;
				memo = 0;
				break;
			}
			case 2: {
				sum = '0' + sum;
				memo = 1;
				break;
			}
			case 3: {
				sum = '1' + sum;
				memo = 1;
				break;
			}
			default:
				break;
		}
	}
	if (memo) sum = char(memo + '0') + sum;

	return sum;
}
