#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s);
};

int main(void) {
    Solution solution;
    string s = "loveleetcode";
    int ans = solution.firstUniqChar(s);
    cout << "ans: " << ans << endl;
}

int Solution::firstUniqChar(string s) {
    vector<int> frequency(26, 0);
    for (char c: s) {
        int index = c - 'a';
        frequency[index]++;
    }

    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        if (frequency[index] == 1) return i;
    }

    return -1;
}