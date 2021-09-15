#include <iostream>
using namespace std;

class Solution {
public:
	void printNGE1(int arr[], int n);
	void printNGE2(int arr[], int n);
};

int main(void) {
	Solution solution;
	int input[] = {11, 13, 21, 3};
	int n = sizeof(input) / sizeof(input[0]);

	// Method 1
	solution.printNGE1(input, n);

	// Method 2
	solution.printNGE2(input, n);
}

void Solution::printNGE1(int arr[], int n) {
	// Method1: use two loops

	int next;
	for (int i = 0; i < n; i++) {
		next = -1;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				next = arr[j];
				break;
			}
		}
		cout << arr[i] << " --> " << next << endl;
	}
}

void Solution::printNGE2(int arr[], int n) {
	// Method: using stack
}