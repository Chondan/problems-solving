#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n);
};

int main(void) {
    Solution solution;
    int input1 = 16;
    int input2 = 3;
    bool ans = solution.isPowerOfTwo(input2);
    cout << "ans: " << ans << endl;
}

bool Solution::isPowerOfTwo(int n) {

    if (n < 0) return false;

    int countOne = 0;
    while (n != 0) {
        int lastDigit = n & 1;
        if (lastDigit) countOne++;
        n >>= 1;
    }

    return countOne == 1 ? true : false;

    // ---- Similar solution but shorter ---- 
    // Example: n = 4 (100), n - 1 = 3 (011) -> n & (n - 1) = 0
    // return (n > 0 && (n & (n - 1)) == 0); 
}