#include <unordered_set>
#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {3, 2, 3, 4, 6, 5};
    vector<int> ans = solution.findErrorNums(nums);
    cout << "ans: " << endl;
    displayVector<int>(ans);
}

vector<int> Solution::findErrorNums(vector<int> &nums) {
    int len = nums.size();
    unordered_set<int> memo;

    int actualSum = 0, duplicateNum;
    bool isFound = false;
    for (int i = 0; i < len; i++) {
        int num = nums[i];
        actualSum += num;

        if (isFound) continue;
        if (memo.find(num) == memo.end()) {
            memo.insert(num);
        } else {
            duplicateNum = num;
            isFound = true;
        }
    }

    int theorySum = len * (len + 1) / 2;
    int repeatedNum = theorySum - (actualSum - duplicateNum);
    return {duplicateNum, repeatedNum};
}
/*
1. loop through array
    - to find sum (actual sum)
    - to find duplicate number
2. can get repetition one from -> theory sum - (actual sum - duplicate number)
    - theory sum = n * (n + 1) / 2
*/