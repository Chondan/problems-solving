#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k);
    bool containsNearbyDuplicate2(vector<int> &nums, int k);
};

int main(void) {
    Solution solution;
    vector<int> input1 = {1, 2, 3, 1};
    int k1 = 3;
    vector<int> input2 = {1, 2, 3, 1, 2, 3};
    int k2 = 2;
    bool ans = solution.containsNearbyDuplicate2(input2, k2);
    cout << "ans: " << ans << endl;
}

// Time exceed
bool Solution::containsNearbyDuplicate(vector<int> &nums, int k) {

    int len = nums.size();
    for (int i = 0; i < len; i++) {
        int pointer = i + k;
        pointer = min(pointer, len - 1);
        while (pointer > i) {
            if (nums[i] == nums[pointer]) return true;
            pointer--;
        }
    }
    return false;

}

bool Solution::containsNearbyDuplicate2(vector<int> &nums, int k) {

    unordered_map<int, int> memo;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        int num = nums[i];
        if (memo.find(num) != memo.end()) {
            int diff = abs(memo[num] - i);
            if (diff <= k) return true;
        }
        memo[num] = i;
    }
    return false;

}