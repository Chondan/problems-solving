#include <iostream>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal);
};

int main(void) {
    Solution solution;
    string s = "abcde", goal = "cdeab";
    bool ans = solution.rotateString(s, goal);
    cout << "ans: " << ans << endl;
}

bool Solution::rotateString(string s, string goal) {
    int lenGoal = goal.length();

    if (s == goal) return true;
    if (s.length() != lenGoal) return false;

    char firstChar = s[0];
    // Find firstCar of s in goal
    for (int i = 0; i < lenGoal; i++) {
        if (firstChar == goal[i]) {
            // Assume i = 3 (cdeab) -> goal.substr(i, lenGoal - 1 - i) + goal.substr(0, i);
            string rotatedString = goal.substr(i, lenGoal - i) + goal.substr(0, i);
            if (rotatedString == s) return true;
        }
    }

    return false;
}