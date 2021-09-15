#include <vector>
#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right);
    bool isSelfDividingNumber(int number);
};

int main(void) {
    Solution solution;
    int left = 1, right = 500;
    vector<int> ans = solution.selfDividingNumbers(left, right);
    cout << "ans: " << endl;
    displayVector<int>(ans);
}

vector<int> Solution::selfDividingNumbers(int left , int right) {
    vector<int> ans;
    for (int i = left; i <= right; i++) {
        if (this->isSelfDividingNumber(i)) ans.push_back(i);
    }
    return ans;
}

bool Solution::isSelfDividingNumber(int number) {
    int num = number; // Copy of number
    while (num > 0) {
        int lastDigit = num % 10;
        if (lastDigit == 0 || number % lastDigit != 0) return false;
        num /= 10;
    }

    return true;
}