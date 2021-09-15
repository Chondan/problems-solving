#include <vector>
#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    vector<int> countBits(int n);
    // Another approach which is faster
    vector<int> countBits2(int n);
};

int main(void) {
    Solution solution;
    int input = 5;
    vector<int> ans = solution.countBits2(input);
    cout << "ans: " << endl;
    displayVector(ans);
}

vector<int> Solution::countBits(int n) {
    vector<int> ans;

    for (int i = 0; i <= n; i++) {
        int num = i;
        int count = 0;

        if (num % 2 == 0) {
            ans.push_back(1);
            continue;
        }

        while (num != 0) {
            int lastDigit = num & 1;
            if (lastDigit == 1) count++;
            num >>= 1;
        }
        ans.push_back(count);
    }

    return ans;
}

vector<int> Solution::countBits2(int n) {

    // If a number is odd. Number of ones will be 1+number of ones
    // in previous number(even).

    // If a number is even. Number of ones is same as number of ones
    // in n/2. Because when we multiplying a number by 2, the binary
    // will be shifted to the left by one place e.g. 6(0110) -> 12(1100)
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            ans[i] = ans[i - 1] + 1;
        } else {
            ans[i] = ans[i / 2];
        }
    }
    return ans;
}