#include <vector>
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

class Solution {
public:
	void rotate(vector<vector<int>> &matrix);
};

int main(void) {
	Solution solution;

 	vector<vector<int>> input = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}; 
 	solution.rotate(input);

}

void Solution::rotate(vector<vector<int>> &matrix) {
	int size = matrix.size();	

	// Taking transpose
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	// Swapint the columns
	for (int i = 0; i < size; i++) {
		int left = 0, right = size - 1;
		while (left < right) {
			swap(matrix[i][left++], matrix[i][right--]);
		}
	}
}
