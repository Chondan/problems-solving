#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSegments(string s);
};

int main(void) {
    Solution solution;
    string s = "Hello, my name is John";
    int ans = solution.countSegments(s);
    cout << "ans: " << ans << endl;
}

int Solution::countSegments(string s) {
    stringstream ss(s);
    string word;

    int count = 0;
    while (ss >> word) {
        count++;
    }

    return count;
}