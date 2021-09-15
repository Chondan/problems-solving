#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<char, int> getMemo(string s);

class Solution {
public:
    bool isAnagram(string s, string t);
    // Another approach which is faster
    bool isAnagram2(string s, string t);
};

int main(void) {
    Solution solution;
    string s = "car";
    string t = "rat";
    bool ans = solution.isAnagram2(s, t);
    cout << "ans: " << ans << endl;
}

bool Solution::isAnagram(string s, string t) {

    if (s.length() != t.length()) return false;

    map<char, int> m1 = getMemo(s);
    map<char, int> m2 = getMemo(t);
    if (m1.size() != m2.size()) return false;

    map<char, int>::iterator itr1;
    map<char, int>::iterator itr2;
    for (itr1 = m1.begin(), itr2 = m2.begin(); itr1 != m1.end(); itr1++, itr2++) {
        if (itr1->first != itr2->first) return false;
        if (itr1->second != itr2->second) return false;
    }

    return true;
}

map<char, int> getMemo(string s) {
    map<char, int> memo;
    for (auto c: s) {
        if (memo.find(c) == memo.end()) {
            memo[c] = 1;
        } else {
            memo[c]++;
        }
    }
    return memo;
}

bool Solution::isAnagram2(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<int> memo(26, 0);

    for (auto c: s) {
        int index = c - 'a';
        memo[index]++;
    }

    for (auto c: t) {
        int index = c - 'a';
        memo[index]--;

        if (memo[index] < 0) return false;
    }

    return true;
}