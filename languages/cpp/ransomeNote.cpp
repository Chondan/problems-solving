#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine);
};

int main(void) {
    Solution solution;
    string ransomNote = "a", magazine = "b";
    bool ans = solution.canConstruct(ransomNote, magazine);
    cout << "ans: " << ans << endl;
}

bool Solution::canConstruct(string ransomNote, string magazine) {

    vector<int> freq(26, 0);
    for (char c: magazine) {
       int index = c - 'a';
       freq[index]++; 
    }

    for (char c: ransomNote) {
        int index = c - 'a';
        freq[index]--;
        if (freq[index] < 0) return false;
    }

    return true;
}