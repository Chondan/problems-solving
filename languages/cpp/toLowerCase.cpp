#include <iostream>
using namespace std;

class Solution {
public:
    string toLowerCase(string s);
};

int main(void) {
    Solution solution;
    string s = "Hello";
    string ans = solution.toLowerCase(s);
    cout << "ans: " << ans << endl;
}

string Solution::toLowerCase(string s) {
    string ans = "";
    for (char c: s) {
        int ascii = c;
        if (ascii >= 65 && ascii <= 90) {
            ascii += 32; 
        }
        ans += char(ascii); 
    } 
    return ans; 
}