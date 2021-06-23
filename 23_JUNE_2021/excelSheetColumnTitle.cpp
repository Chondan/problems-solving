#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber);
};

int main(void) {
	Solution solution;
	int columnNumber = 53;
	string ans = solution.convertToTitle(columnNumber);
	cout << "ans: " << ans << endl;
}

string Solution::convertToTitle(int columnNumber) {
	int beforeA = 64; // char A = base@ + 1
	int base = 26;
	string ans = "";

	while (columnNumber > 0) {
		int f = columnNumber % base;
		char c = f == 0 ? beforeA + 26 : beforeA + f;
		ans = c + ans;
		if (c == 'Z') {
			columnNumber--;
		}	
		cout << columnNumber << endl;
		columnNumber /= 26;
	}

	return ans;	
}

/* 

AZ -> 52

*/