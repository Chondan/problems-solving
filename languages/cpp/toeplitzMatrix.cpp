#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix);
};

int main(void) {
    Solution solution;
    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    bool ans = solution.isToeplitzMatrix(matrix);
    cout << "ans: " << ans << endl;
}

bool Solution::isToeplitzMatrix(vector<vector<int>> &matrix) {

    int numOfRows = matrix.size(), numOfCols = matrix[0].size();
    bool ans = true;

    // Loop through first rows
    int start;
    for (int i = 0; i < numOfCols; i++) {
        start = matrix[0][i];

        int row = 1, col = i + 1;
        while (row < numOfRows && col < numOfCols) {
            if (start != matrix[row][col]) {
                return false;
            }
            row++;
            col++;
        }

    }

    // Loop through first columns
    for (int j = 1; j < numOfRows; j++) {
        start = matrix[j][0];

        int row = j + 1, col = 1;
        while (row < numOfRows && col < numOfCols) {
            if (start != matrix[row][col]) {
                return false;
            }
            row++;
            col++;
        }

    }

    return ans;
}

/* 

Loop first row and first col

check (x, y) and (x + 1, y + 1) ...

*/
