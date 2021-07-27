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
    if (ops.empty()) return m * n;

    int row = m + 1, col = n + 1;
    int ans = ops[0][0] * ops[0][1];
    for (int i = 1; i < ops.size(); i++) {
        int candidateRow = ops[i][0], candidateCol = ops[i][1];
        row = min(candidateRow, row);
        col = min(candidateCol, col); 
    }
    ans = min(ans, row * col);

    return ans;
}
