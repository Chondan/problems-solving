#include <iostream>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s);
    bool helper(string s, int left, int right);
};

int main(void) {
    Solution solution;
    string s = "abca";
    bool ans = solution.validPalindrome(s);
    cout << "ans: " << ans << endl;
}

bool Solution::validPalindrome(string s) {

    int left = 0, right = s.length() - 1;
    while (left <= right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            return this->helper(s, left + 1, right) || this->helper(s, left, right - 1);
        }
    }

    return true;
}

bool Solution::helper(string s, int left, int right) {

    while (left <= right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            return false;
        }
    }

    return true;
}