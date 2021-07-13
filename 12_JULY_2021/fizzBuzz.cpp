#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n);
};

int main(void) {
    Solution solution;
    int n = 15;
    vector<string> ans = solution.fizzBuzz(n);
    cout << "ans:" << endl;
    displayVector(ans);
}

vector<string> Solution::fizzBuzz(int n) {
    vector<string> ans;

    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            ans.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
            ans.push_back("Fizz");
        } else if (i % 5 == 0) {
            ans.push_back("Buzz");
        } else {
            ans.push_back(to_string(i));
        }
    }

    return ans;
}