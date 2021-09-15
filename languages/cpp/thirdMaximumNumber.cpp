#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {3, 2, 4, 1};
    int ans = solution.thirdMax(nums);
    cout << "ans: " << ans << endl;
}

// Can be optimized
int Solution::thirdMax(vector<int> &nums) {
    // [max, medium, min]
    vector<int> rank(3, INT_MIN);
    set<int> memo;

    for (int num: nums) {
        if (memo.find(num) != memo.end()) continue;

        for (int i = 0; i < 3; i++) {
            if (num >= rank[i]) {
                memo.insert(num);

                if (i == 0) {
                    rank[2] = rank[1];
                    rank[1] = rank[0];
                    rank[0] = num;
                    break;
                } else if (i == 1) {
                    rank[2] = rank[1];
                    rank[1] = num;
                    break;
                } else {
                    rank[2] = num;
                    break;
                }
            }
        }
    }
    return memo.size() < 3 ? rank[0] : rank[2];
}