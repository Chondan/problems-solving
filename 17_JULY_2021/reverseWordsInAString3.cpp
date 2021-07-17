#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s);
    void doReverseWord(string &s);
};

int main(void) {
    Solution solution;
    string s = "Let's take LeetCode contest";
    string ans = solution.reverseWords(s);
    cout << "ans: " << ans << endl;
}

string Solution::reverseWords(string s) {
    stringstream ss(s);
    string word;

    string ans = "";
    while (ss >> word) {
        this->doReverseWord(word); // Can use `reverse(begin(word), end(word))`
        ans += word + " ";
    }

    return ans.substr(0, ans.length() - 1);
}

void Solution::doReverseWord(string &s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        swap(s[l++], s[r--]);
    }
}