#include <unordered_map>
#include <stack>
#include <vector>
#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2);
    // Another approach using stack which is faster
    vector<int> nextGreaterElement2(vector<int> &nums1, vector<int> &nums2);
};

int main(void) {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = solution.nextGreaterElement2(nums1, nums2);
    cout << "ans:" << endl;
    displayVector<int>(ans);
}

vector<int> Solution::nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    vector<int> ans(len1, -1);

    for (int i = 0; i < len1; i++) {
        bool isFound = false;
        for (int j = 0; j < len2; j++) {
            if (nums2[j] == nums1[i]) isFound = true;

            if (nums2[j] > nums1[i] && isFound) {
                ans[i] = nums2[j];
                break;
            }
        }
    }
    return ans;
}

vector<int> Solution::nextGreaterElement2(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> memo;
    stack<int> s;
    for (int num: nums2) {
        // If there is no next greater element, then the answer for this query is -1
        memo[num] = -1;
        while (!s.empty() && num > s.top()) {
            int top = s.top();
            memo[top] = num;
            s.pop();
        }

        s.push(num);
    }

    vector<int> ans;
    for (int num: nums1) {
        ans.push_back(memo[num]);
    }

    return ans;
}