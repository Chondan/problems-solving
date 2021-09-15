#include <iostream>
using namespace std;

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    return false;
}

class Solution {
public:
    string reverseVowels(string s);
    string reverseVowels2(string s);
};

int main(void) {
    Solution solution;
    string input = "leetcode";
    string ans = solution.reverseVowels2(input);
    cout << "ans: " << ans << endl;
}

string Solution::reverseVowels(string s) {
    string vowels = "";
    for (char c: s) {
        if (isVowel(c)) {
            vowels += c;
        }
    }

    int pos = vowels.length() - 1;
    string ans = "";
    for (char c: s) {
        if (isVowel(c)) {
            ans += vowels[pos--];
        } else {
            ans += c;
        }
    }
    return ans;
}

string Solution::reverseVowels2(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (!isVowel(s[l])) {
            l++;
            continue;
        }
        if (!isVowel(s[r])) {
            r--;
            continue;
        }
        swap(s[l], s[r]);
        l++;
        r--;
    }
    return s;
}