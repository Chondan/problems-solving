#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>> &ops);
};

int main(void) {
    Solution solution;
    vector<vector<int>> ops = {{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3}};
    int m = 3, n = 2;
    int ans = solution.maxCount(m, n, ops);
    cout << "ans: " << ans << endl;
}

int Solution::maxCount(int m, int n, vector<vector<int>> &ops) {
    return 9;
}
