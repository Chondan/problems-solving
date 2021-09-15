#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t);
    char findTheDifference2(string s, string t);
    // Bit manipulation
    char findTheDifference3(string s, string t);
};

int main(void) {
    Solution solution;
    string s = "abcd", t = "abcde";
    char ans = solution.findTheDifference3(s, t);
    cout << "ans: " << ans << endl;
}

char Solution::findTheDifference(string s, string t) {
    unordered_map<char, int> memo;
    for (char c: s) {
        if (memo.find(c) == memo.end()) {
            memo[c] = 1;
        } else {
            memo[c]++;
        }
    }

    char ans;
    for (int i = 0; i < t.length(); i++) {
        char c = t[i];
        if (memo.find(c) == memo.end()) {
            ans = c;
            break;
        } else {
            if (memo[c] == 0) {
                ans = c;
                break;
            }
            memo[c]--;
        }
    }

    return ans;
}

// Faster than using unordered_map
char Solution::findTheDifference2(string s, string t) {
    vector<int> frequency(26, 0);
    for (char c: s) {
        int index = c - 'a';
        frequency[index]++;
    }

    char ans;
    for (int i = 0; i < t.length(); i++) {
        char c = t[i];
        int index = c - 'a';
        if (frequency[index] == 0) {
            ans = c;
            break;
        } else {
            if (frequency[index] == 0) {
                ans = c;
                break;
            }
            frequency[index]--;
        }
    }

    return ans;
}

// Fastest
char Solution::findTheDifference3(string s, string t) {
    int ascii = t[t.length() - 1];

    for (int i = 0; i < s.length(); i++) {
        ascii = ascii ^ s[i] ^ t[i];
    }

    return char(ascii);
}

