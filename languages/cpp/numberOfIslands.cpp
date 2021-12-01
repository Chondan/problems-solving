#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid);
    void setAdjacentsToZero(vector<vector<char>> &grid, int i, int j);
};

int main(void) {
    Solution solution;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    int ans = solution.numIslands(grid);
    cout << "ans: " << ans << endl;
}

int Solution::numIslands(vector<vector<char>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    int ans = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == '1') {
                ans += 1;

                // Set itself and all adjacents to zero
                this->setAdjacentsToZero(grid, i, j);
            }
        }
    }

    return ans; 
}

void Solution::setAdjacentsToZero(vector<vector<char>> &grid, int i, int j) {
    // Stop if out bound or current position (i, j) is alredy set to zero
    int leftBound = 0;
    int rightBound = grid[0].size();
    int topBound = 0;
    int bottomBound = grid.size();

    bool isOutBound = j < leftBound || j >= rightBound || i < topBound || i >= bottomBound;
    if (isOutBound || grid[i][j] == '0') return;

    grid[i][j] = '0';
    this->setAdjacentsToZero(grid, i - 1, j); // top
    this->setAdjacentsToZero(grid, i, j + 1); // right
    this->setAdjacentsToZero(grid, i + 1, j); // bottom
    this->setAdjacentsToZero(grid, i, j - 1); // left
}
