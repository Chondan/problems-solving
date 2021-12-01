#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height);
};

int main(void) {
    Solution solution;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int ans = solution.maxArea(height);
    cout << "ans: " << ans << endl;
}

int Solution::maxArea(vector<int> &height) {

    int ans = INT_MIN;
    int left = 0, right = height.size() - 1;
    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        ans = max(ans, area);

        // Keep higher bar
        if (height[left] > height[right]) {
           right--; 
        } else {
            left++;
        }
    }

    return ans;
}