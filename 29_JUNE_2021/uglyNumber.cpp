#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n);
};

int main(void) {
    Solution solution;
    int input1 = 14;
    int input2 = 30;
    bool ans = solution.isUgly(input2);
    cout << "ans: " << ans << endl;
}

bool Solution::isUgly(int n) {

    if (n == 1) return true;

    int cur = n;
    if (cur % 2 == 0) cur /= 2;
    if (cur % 3 == 0) cur /= 3;
    if (cur % 5 == 0) cur /= 5;
    
    // 2, 3, 5, is not factors of n then return false
    if (cur == n) return false;
    return this->isUgly(cur);
}