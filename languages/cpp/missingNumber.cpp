#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> input = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int ans = solution.missingNumber(input);
    cout << "ans: " << ans << endl;
}

int Solution::missingNumber(vector<int> &nums) {
    int n = 0, curSum = 0;
    for (int num: nums) {
        n++;
        curSum += num;
    }    
    int totalSum = n * (n + 1) / 2;

    return totalSum - curSum;
}