#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s);
};

int main(void) {
    Solution solution;
    string s = "abccccdd";
    int ans = solution.longestPalindrome(s);
    cout << "ans: " << ans << endl;
}

int Solution::longestPalindrome(string s) {

    // lowercase and uppercase
    vector<int> frequency(52, 0);

    for (char c: s) {
        int charIndex = int(c);
        int frequencyIndex = charIndex < 97 ? charIndex - 65 : charIndex - 97 + 26;
        frequency[frequencyIndex]++; 
    }

    int len = 0;
    for (int freq: frequency) {
        if (freq % 2 == 0) {
            len += freq;
        } else {
            len += freq - 1;
        }
    }

    if (len < s.length()) {
        len += 1;
    }

    return len;
}