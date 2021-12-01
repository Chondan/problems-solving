#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target);
};

int main(void) {
    Solution solution;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int ans = solution.search(nums, target);
    cout << "ans: " << ans << endl;
}

int Solution::search(vector<int> &nums, int target) {

    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int middle = left + ((right - left) / 2);
        if (nums[middle] == target) {
            return middle;
        } else {
            if (nums[middle] < target) left = middle + 1;
            else right = middle - 1;
        }
    }

    return -1;
}