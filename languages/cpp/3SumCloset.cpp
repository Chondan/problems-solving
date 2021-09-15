#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target);
};

int main(void) {
    Solution solution;
    vector<int> input = {-1, 2, 1, -4};
    int target = 1;
    int ans = solution.threeSumClosest(input, target);
    cout << "ans: " << ans << endl;
}

int Solution::threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int initialSum = nums[0] + nums[1] + nums[2];
    int diff = abs(target - initialSum);
    int ans = initialSum;
    for (int i = 0; i < nums.size() - 2; i++) {
        int a = nums[i], l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int b = nums[l], c = nums[r];
            int sum = a + b + c;
            int newDiff = abs(target - sum);
            if (newDiff < diff) {
                ans = sum;
                diff = newDiff; 
            }
            if (sum < target) l++;
            else r--; 

            if (ans == target) return ans;
        }
    }
    return ans;
}