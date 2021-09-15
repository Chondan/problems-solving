#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n);
    // Better solution
    int trailingZeroes2(int n);
};

int main(void) {
	Solution solution;
	int input = 40;
	int ans = solution.trailingZeroes2(input); // 9
	cout << "ans: " << ans << endl;
}

int Solution::trailingZeroes(int n) {
	if (n == 0) return 0;

	int count = 0;
	for (int i = 1; i <= n; i++) {

		int num = i;
		if (num % 10 == 0) {
			count++;
			num /= 10;
		} 

		if (num % 5 == 0) {
			while (num > 0 && num % 5 == 0) {
				num /= 5;
				count++;
				if (num / 5 == 0) break;
			}
		}
	}

	return count;
}

// Number of trailing zeros in factorials
// = [n/5] + [n/25] + [n/125] + ... + [n/(5^x)]; n/(5^x) = 0
// As the number of 2's will always be greater than
// no. of 5's ..so the number of 5's is deciding factor.
int Solution::trailingZeroes2(int n) {
	int count = 0;
	for (int i = 5; i <= n; i *= 5) {
		count += (n / i);
	}
	return count;
}