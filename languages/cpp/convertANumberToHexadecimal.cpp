#include <iostream>
using namespace std;

class Solution {
public:
    string toHex(int num);
};

int main(void) {
    Solution solution;
    int num = 16;
    string ans = solution.toHex(num);
    cout << "ans: " << ans << endl;
}

string Solution::toHex(int num) {
    if (num == 0) return "0";

    // ascii -> a = 97
    string ans = "";
    for (int i = 0; i < 8; i++) {
        int last4Digit = num & 0x0000000f;
        num >>= 4;
        if (last4Digit == 0 && num == 0) break;

        char c = last4Digit < 10 ? last4Digit + '0' : last4Digit + 87;
        ans = c + ans;
    }

    return ans;
}