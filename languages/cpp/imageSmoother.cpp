#include <vector>
#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img);
    int getAverageOfSurrondingCells(int x, int y, int row, int col, vector<vector<int>> &img);
};

int main(void) {
    Solution solution;
    vector<vector<int>> img = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
    vector<vector<int>> ans = solution.imageSmoother(img);
    cout << "ans:" << endl;
    displayVectorVector<int>(ans);
}

vector<vector<int>> Solution::imageSmoother(vector<vector<int>> &img) {
    int row = img.size();
    int col = img[0].size();
    vector<vector<int>> ans(row, vector<int>(col));

    for (int x = 0; x < col; x++) {
        for (int y = 0; y < row; y++) {
            int avgOfSurrondingCells = this->getAverageOfSurrondingCells(x, y, row, col, img);
            ans[y][x] = avgOfSurrondingCells;
        }
    }

    return ans;
}

/* 
--- Get index of 8 surronding cells ---
assume starting with index (1, 1) -> (x, y)

cell1 -> (x - 1, y - 1)
cell2 -> (x, y - 1)
cell3 -> (x + 1, y - 1)
cell4 -> (x - 1, y)
self  -> (x, y)
cell5 -> (x + 1, y)
cell6 -> (x - 1, y + 1)
cell7 -> (x, y + 1)
cell8 -> (x + 1, y + 1)
*/
int Solution::getAverageOfSurrondingCells(int x, int y, int row, int col, vector<vector<int>> &img) {
    // Calculate Boundary (index)
    int leftBound = 0;
    int rightBound = col - 1;
    int topBound = 0;
    int bottomBound = row - 1; 


    // Loop -> start index from i = x - 1, j = y - 1 to i = x + 1, j = y + 1
    int startI = x - 1, endI = x + 1;
    int startJ = y - 1, endJ = y + 1;
    int sum = 0, count = 0;
    for (int i = startI; i <= endI; i++) {
        for (int j = startJ; j <= endJ; j++) {
            if (i < leftBound || i > rightBound || j < topBound || j > bottomBound) continue;
            sum += img[j][i];
            count++;
        }
    }

    int avg = sum / count;
    return avg;
}
