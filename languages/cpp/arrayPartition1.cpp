#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {6,2,6,5,1,2};
    int ans = solution.arrayPairSum(nums);
    cout << "ans: " << ans << endl; 
}

 int Solution::arrayPairSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i % 2 == 0) {
            ans += nums[i];
        }
    }

    return ans;
 }