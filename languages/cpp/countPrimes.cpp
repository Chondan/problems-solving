#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n);
    bool isPrime(int n);
};

int main(void) {
	Solution solution;
	int input = 10;
	int ans = solution.countPrimes(input);
	cout << "ans: " << ans << endl;
}

int Solution::countPrimes(int n) {
	if (n == 1 || n == 0) return 0;

	vector<int> ans;
	vector<bool> isPrimes(n + 1, true);
	for (int i = 2; i < n; i++) {
		if (isPrimes[i]) ans.push_back(i);

		for (int j = i + i; j < n; j += i) {
			isPrimes[j] = false;
		}
	}	

	return ans.size();
}

// WIP: Try another approach