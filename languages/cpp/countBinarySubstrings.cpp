#include <vector>
#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s);
    int countBinarySubstrings2(string s);
};

int main(void) {
    Solution solution;
    string s = "0010011";
    int ans = solution.countBinarySubstrings2(s);
    cout << "ans: " << ans << endl;
}

// Approach 1: Gorup By character
int Solution::countBinarySubstrings(string s) {
    vector<int> groups;
    int consequence = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == s[i]) {
            consequence += 1;
        } else {
            groups.push_back(consequence);
            consequence = 1;
        }
    }
    groups.push_back(consequence);


    // Count the number of valid binary strings between
    // groups[i] and groups[i+1]
    int count = 0;
    for (int i = 1; i < groups.size(); i++) {
        count += min(groups[i-1], groups[i]);
    }

    return count;
}

// Approach 2: Linear Scan
int Solution::countBinarySubstrings2(string s) {
    int count = 0;
    int prev = 0, cur = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == s[i]) {
            cur += 1;
        } else {
            count += min(prev, cur);
            prev = cur;
            cur = 1;
        }
    }
    count += min(prev, cur);

    return count;
}