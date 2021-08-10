#include <unordered_map>
#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor);
    void helper(vector<vector<int>> &image, int sr, int sc, int startColor, int newColor, unordered_map<string, bool> &visited);
};

int main(void) {
	Solution solution;
	vector<vector<int>> image = {{0,0,0},{0,0,0}};
	int sr =1, sc = 1, newColor = 2;
	vector<vector<int>> ans = solution.floodFill(image, sr, sc, newColor);
	cout << "ans:" << endl;
	displayVectorVector<int>(ans);
}

vector<vector<int>> Solution::floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
	unordered_map<string, bool> visited;
	int startColor = image[sr][sc];
	this->helper(image, sr, sc, startColor, newColor, visited);

	return image;
}

void Solution::helper(vector<vector<int>> &image, int sr, int sc, int startColor, int newColor, unordered_map<string, bool> &visited) {
	int numberOfRow = image.size();
	int numberOfColumn = image[0].size();
	string key = to_string(sr) + to_string(sc);

	// Break conditions
	bool invalidRow = sr < 0 || sr >= numberOfRow;
	bool invalidCol = sc < 0 || sc >= numberOfColumn;

	if (invalidRow || invalidCol) return;
	if (image[sr][sc] != startColor || visited[key]) return;

	// Update color
	image[sr][sc] = newColor;
	visited[key] = true;

	// Top
	this->helper(image, sr - 1, sc, startColor, newColor, visited);
	// Right
	this->helper(image, sr, sc + 1, startColor, newColor, visited);
	// Bottom
	this->helper(image, sr + 1, sc, startColor, newColor, visited);
	// Left
	this->helper(image, sr, sc - 1, startColor, newColor, visited);
}

/* 
	up -> 0 1
	right -> 1 2
	down -> 2 1
	left -> 1 0
	
	break if 
	- image[sr][sc] != start color
	- sr < 0, sr >= number of row, sc >= number of column, sc < 0
	- the cell is already visited -> visited[cell] = true
*/
