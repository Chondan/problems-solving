#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right);
    int getNumberOfOneBit(int number);
    bool isPrime(int number);
};

int main(void) {
    Solution solution;
    int left = 10, right = 15;
    int ans = solution.countPrimeSetBits(left, right);
    cout << "ans: " << ans << endl;
}

int Solution::countPrimeSetBits(int left, int right) {
    int countPrime = 0;
    for (int num = left; num <= right; num++) {
	int numberOfOneBit = getNumberOfOneBit(num);
	cout << "numberOfOneBit: " << numberOfOneBit << endl;
	if (isPrime(numberOfOneBit)) countPrime += 1;
    }

    return countPrime;
}

int Solution::getNumberOfOneBit(int number) {
    int countOneBit = 0;

    while (number > 0) {
	int lastBit = number & 1;
	if (lastBit == 1) countOneBit += 1;
	number = number >> 1;
    }

    return countOneBit;
}

bool Solution::isPrime(int number) {
    if (number <= 1) return false;

    for (int i = 2; i <= number / 2; i++) {
	if (number % i == 0) return false; 
    }

    return true;
}
