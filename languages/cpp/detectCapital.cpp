#include <string>
#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word);
};

int main(void) {
    Solution solution;
    string word = "leetCode";
    bool ans = solution.detectCapitalUse(word);
    cout << "ans: " << ans << endl;
}

bool Solution::detectCapitalUse(string word) {
    // Check all uppercase and all lowercase
    bool allUpper = true, allLower = true;
    int countUpper = 0;
    for (char w: word) {
        bool isUpper = isUpperCase(w);
        if (isUpper) countUpper++;

        allUpper = allUpper && isUpper;
        allLower = allLower && !isUpperCase(w);
    }
    if (allUpper || allLower) return true;

    // Check first char uppercase
    if (countUpper == 1 && isUpperCase(word[0])) return true;

   return false; 
}