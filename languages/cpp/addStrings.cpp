#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2);
};

int main(void) {
    Solution solution;
    string num1 = "1", num2 = "9";
    string ans = solution.addStrings(num1, num2);
    cout << "ans: " << ans << endl;
}

string Solution::addStrings(string num1, string num2) {
    string ans = "";

    int len1 = num1.length(), len2 = num2.length();
    int index1 = len1 - 1, index2 = len2 - 1; 

    int memo = 0;
    while (index1 >= 0 || index2 >= 0) {
        int val1 = index1 >= 0 ? charToInt(num1[index1--]) : 0;
        int val2 = index2 >= 0 ? charToInt(num2[index2--]) : 0;
        int sum = val1 + val2 + memo;

        ans = intToChar(sum % 10) + ans;
        memo = sum / 10;
    }
    if (memo != 0) {
        ans = intToChar(memo) + ans;
    }

    return ans;
}