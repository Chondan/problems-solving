#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t);
};

int main(void) {
    Solution solution;
    string s = "ahbc", t = "ahbgdc";
    bool ans = solution.isSubsequence(s, t);
    cout << "ans: " << ans << endl;
}

bool Solution::isSubsequence(string s, string t) {
    string check = "";

    // to loop throuh string s
    int pos = 0;

    for (char c: t) {
        if (c == s[pos]) {
            check += c;
            pos++;
        }
    }

    return check == s;
}