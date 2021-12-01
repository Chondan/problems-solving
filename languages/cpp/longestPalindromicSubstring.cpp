#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s);
    int getLenPalindrom(string s, int start, int end); // Expand from the middle
};

int main(void) {
    Solution solution;
    string s = "a";
    string ans = solution.longestPalindrome(s);
    cout << "ans: " << ans << endl;
}

string Solution::longestPalindrome(string s) {
    if (s == "") return "";

    int startIndexOfPalindrome = 0, endIndexOfPalindrome = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = this->getLenPalindrom(s, i, i);
        int len2 = this->getLenPalindrom(s, i, i + 1);
        int len = max(len1, len2);

        if (len > endIndexOfPalindrome - startIndexOfPalindrome) {
            startIndexOfPalindrome = i - ((len - 1) / 2);
            endIndexOfPalindrome = i + (len / 2);
        }
    }

    return s.substr(startIndexOfPalindrome, endIndexOfPalindrome - startIndexOfPalindrome + 1);
}

int Solution::getLenPalindrom(string s, int start, int end) {
    if (s == "" || start > end) return 0;

    while (start >= 0 && end < s.length()) {
        if (s[start] != s[end]) break;

        start--;
        end++;
    }

    return end - start - 1;
}