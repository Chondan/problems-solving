#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle);
};

int main(void) {
    Solution solution;
    string columnTitle = "BBA";
    int ans = solution.titleToNumber(columnTitle); // 1405
    cout << "ans: " << ans << endl;
}

int Solution::titleToNumber(string columnTitle) {
    int ans = 0;
    int beforeA = '@';
    int len = columnTitle.length();
    int expo = len - 1;
    for (int i = 0; i < len; i++) {
        char alphabet = columnTitle[i];
        int alphabetNum = alphabet - beforeA;
        ans += pow(26, expo) * alphabetNum;
        expo--;
    }
    return ans;
}

/* 
BA -> 53
ZY -> 26(26) + 25
ZZ -> 26(26) + 26
AAA -> 26(26) + 26 + 1
BBA -> 26(26)(2) + 26(2) + 1
*/