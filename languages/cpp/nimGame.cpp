#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n);
};

int main(void) {
    Solution solution;
    int input = 4;
    bool ans = solution.canWinNim(input);
    cout << "ans: " << ans << endl;
}

bool Solution::canWinNim(int n) {
    if (n % 4 == 0) return false;
    return true;
}