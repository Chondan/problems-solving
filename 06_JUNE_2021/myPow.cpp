#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {

		if (x == 0 || x == 1 || n == 1) return x;
		if (n == 0) return 1;
		int xSign = (x >= 0) ? 0 : 1;
		int nSign = (n >= 0) ? 0 : 1;

		x = (double)abs(x);
		n = (int)abs(n);

		double ans = 1;
		double a = x;
		int t = n;
		while (n > 0) {
			if (n & 1) {
				// odd
				ans *= a;
			}
			n >>= 1; // n /= 2
			a *= a;
		}
		if (xSign && (t & 1)) ans *= -1;
		if (nSign) ans = 1/ans;
		return ans;	
	}

	double myPow2(double x,int n) {
		if (n == 0) return 1;

		double t = myPow2(x, n / 2);;
		if (n % 2 == 0) {
			return t * t;
		} else {
			return n > 0 ? x * t * t : 1 / x * t * t;
		}
	}
};

int main(void) {

	Solution solution;
	double ans = solution.myPow2(2, -4);
	cout << "ans: " << ans << endl;
}

// 1 -> 00000001
// 3 -> 00000011
// 0111 = 7 
// 0011 = 3