#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k);
    double getAverage(int sum, int n);
};

int main(void) {
    Solution solution;
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    double ans = solution.findMaxAverage(nums, k);
    cout << "ans: " << ans << endl;
}

double Solution::findMaxAverage(vector<int> &nums, int k) {

    int len = nums.size();
    int lastPossibleIndexToLoopThrough = len - k;

    // Find starting k sum
    int ksum = 0;
    for (int i = 0; i < k; i++) {
        ksum += nums[i];
    }

    double avg = this->getAverage(ksum, k);
    for (int i = 1; i <= lastPossibleIndexToLoopThrough; i++) {
        // Adjust ksum
        int toRemove = nums[i - 1];
        int toAdd = nums[i + k - 1];
        ksum = ksum - toRemove + toAdd;

        avg = max(this->getAverage(ksum, k), avg);
    }

    return avg;
}

double Solution::getAverage(int sum, int n) {
    return double(sum) / n;
}