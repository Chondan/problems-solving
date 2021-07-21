#include <iostream>
using namespace std;

class Solution {
public:
    string convertToBase7(int num);
};

int main(void) {
    Solution solution;
    int num = -444;
    string ans = solution.convertToBase7(num);
    cout << "ans: " << ans << endl;
}

string Solution::convertToBase7(int num) {
    if (num == 0) return "0";

    int positiveNum = num < 0 ? -1 * num : num;
    string ans = "";
    while (positiveNum != 0) {
        int mod = positiveNum % 7;
        char c = mod + '0';
        ans = c + ans; 
        positiveNum /= 7;
    }

    return num < 0 ? "-" + ans : ans;
}