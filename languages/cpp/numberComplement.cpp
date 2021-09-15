#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num);
};

int main(void) {
	Solution solution;
	int num = 1;
	int ans = solution.findComplement(num);
	cout << "ans: " << ans << endl;
}

int Solution::findComplement(int num) {
	if (num == 1) return 0;

	int binaryLen = 0;
	int x = num;
	while (x > 0) {
		x /= 2;
		binaryLen++;
	}

	// complement
	int ans = 0, base = 2, pos = 0;
	x = num;
	while (binaryLen > 0) {
		bool isEven = x % 2 == 0;
		if (isEven) {
			ans += pow(base, pos);
		}
		binaryLen--;
		pos++;		
		x >>= 1;
	}

	return ans;
}