#include <iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s);
};

int main(void) {
    Solution solution;
    string s = "LLLALL";
    bool ans = solution.checkRecord(s);
    cout << "ans: " << ans << endl;
}

bool Solution::checkRecord(string s) {
    char firstChar = s[0];
    int countA = firstChar == 'A' ? 1 : 0, countConsecutiveL = firstChar == 'L' ? 1 : 0;
    for (int i = 1; i < s.length(); i++) {
        // Absent
        if (s[i] == 'A') countA++;

        // Late
        if (s[i] == 'L') countConsecutiveL = s[i - 1] == 'L' ? countConsecutiveL + 1 : 1;
    
        // Check condition
        if (countConsecutiveL >= 3 || countA >= 2) return false; 
    }

    return true;
}