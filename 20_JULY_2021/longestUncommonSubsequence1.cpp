#include <iostream>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b);
};

int main(void) {
    Solution solution;
    string a = "swoegxvzsfetrdtnoucawucug";
    string b = "gaqrzczpmtsxlwxdacitrcgklziiya";
    int ans = solution.findLUSlength(a, b);
    cout << "ans: " << ans << endl;
}

int Solution::findLUSlength(string a, string b) {
    int lenA = a.length(), lenB = b.length();

    if (a == b) return -1; 
    return max(lenA, lenB);
}