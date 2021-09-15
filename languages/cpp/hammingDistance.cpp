#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y);
};

int main(void) {
	Solution solution;
	int x = 4, y = 1;
	int ans = solution.hammingDistance(x, y);
	cout << "ans: " << ans << endl;
}

int Solution::hammingDistance(int x, int y) {
	int xXORy = x ^ y;

	int countOne = 0;
	while (xXORy > 0) {
		long int result = 1, base = 2;
		while (result * base <= xXORy) {
			result *= base;
		}

		countOne++;
		xXORy -= result;
	}

	return countOne;
}