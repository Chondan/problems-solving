#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid);
};

int main(void) {
	Solution solution;
	vector<vector<int>> input = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
	int ans = solution.islandPerimeter(input);
	cout << "ans: " << ans << endl;
}

int Solution::islandPerimeter(vector<vector<int>> &grid) {

	int perimeter = 0;
	int rowNum = grid.size(), colNum = grid[0].size();


	for (int row = 0; row < rowNum; row++) {
		for (int col = 0; col < colNum; col++) {
			int island = grid[row][col];
			if (island == 0) continue;

			// check 4 side
			// left
			if ((col - 1 >= 0 && grid[row][col - 1] == 0) || col == 0) perimeter++;

			// right
			if ((col + 1 < colNum && grid[row][col + 1] == 0) || col == colNum - 1) perimeter++;

			// up
			if ((row - 1 >= 0 && grid[row - 1][col] == 0) || row == 0) perimeter++;

			// bottom
			if ((row + 1 < rowNum && grid[row + 1][col] == 0) || row == rowNum - 1) perimeter++;
		}
	}

	return perimeter;	
}

// Another approaches
// https://leetcode.com/problems/island-perimeter/discuss/1262356/C%2B%2B-(3-approaches%3A-SImple-and-clean-Interview-style)