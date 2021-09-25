#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost);
};

int main(void) {
    Solution solution;
    vector<int> cost = {1,2,5,11,20,10,33,11,6,1};
    int ans = solution.minCostClimbingStairs(cost);
    cout << "ans: " << ans << endl;
}

int Solution::minCostClimbingStairs(vector<int> &cost) {

    int len = cost.size();
    for (int i = 2; i < len; i++) {
        cost[i] += min(cost[i - 1], cost[i - 2]);
    }

    return min(cost[len - 1], cost[len - 2]);
}