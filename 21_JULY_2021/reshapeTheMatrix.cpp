#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c);
};

int main(void) {
    Solution solution;
    vector<vector<int>> mat = {{1,2,3},{4,5,6}};
    int r = 3, c = 2;
    vector<vector<int>> ans = solution.matrixReshape(mat, r, c);
    cout << "ans:" << endl;
    displayVectorVector<int>(ans);
}

vector<vector<int>> Solution::matrixReshape(vector<vector<int>> &mat, int r, int c) {
    int originalRow = mat.size(), originalCol = mat[0].size();
    int matrixSize = originalRow * originalCol;

    // Illegal
    if (r*c != matrixSize) return mat;

    vector<vector<int>> ans;
    int curRow = 0, curCol = 0;
    int countColElem = 0;
    for (int i = 0; i < r; i++) {
        vector<int> row;
        while (countColElem < c) {
            int elem = mat[curRow][curCol];
            row.push_back(elem);

            countColElem++;
            curCol++;

            if (curCol == originalCol) {
                curCol = 0;
                curRow++;
            } 
        }
        ans.push_back(row);
        countColElem = 0;
    }

    return ans;
}