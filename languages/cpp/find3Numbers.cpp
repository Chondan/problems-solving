#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
	// return true if there is triplet with sum equal 
	// to 'targetSum' present in A[]. Also, prints the triplet
	bool find3Numbers(int A[], int arr_size, int targetSum);
	bool find3Numbers2(int A[], int arr_size, int targetSum);
};

int main(void) {
	Solution solution;
	int input[] = {1, 4, 45, 6, 10, 8};
	int inputSize = sizeof(input) / sizeof(input[0]);
	int targetSum = 22;

	bool ans1 = solution.find3Numbers(input, inputSize, targetSum);
	cout << "ans (solution 1): " << ans1 << endl;

	bool ans2 = solution.find3Numbers2(input, inputSize, targetSum);
	cout << "ans (solution 2): " << ans2 << endl;
}

bool Solution::find3Numbers(int A[], int arr_size, int targetSum) {
	// This method uses sorting to increase the efficiency of the code.
	// This efficient uses the 'two-pointer' technique.

	int l, r;

	// sort the elements
	sort(A, A + arr_size);

	// Now fix the first element one by one and find 
	// the other two elements
	for (int i = 0; i < arr_size - 2; i++) {
		l = i + 1;
		r = arr_size - 1;
		while (l < r) {
			int curSum = A[i] + A[l] + A[r];

			if (curSum > targetSum) {
				r--;
			} else if (curSum < targetSum) {
				l++;
			} else {
				printf("Triplet is %d, %d, %d\n", A[i], A[l], A[r]);
				return true;	
			}
		}
	}

	return false;

}

// --- NOTE ---
// When you pass an array to a function, it decays into a pointer to 
// the first element, at which point knowledge of its size is lots.

// If you want to know the size of an array passed to the function,
// you need to work it out before decay and pass that information with the 
// array.

bool Solution::find3Numbers2(int A[], int arr_size, int targetSum) {
	// This is a Hashing-based solution

	// Fix the first element as A[i]
	for (int i = 0; i < arr_size - 2; i++) {
		// Find pair in subarray A[i+1..n-1]
		// with sum equal to sum - A[i]
		unordered_set<int> s;
		int curTargetSum = targetSum - A[i];
		for (int j = i + 1; j < arr_size; j++) {
			if (s.find(curTargetSum - A[j]) != s.end()) {
				printf("Triplet is %d, %d, %d\n", A[i], A[j], curTargetSum - A[j]);
				return true;
			}
			s.insert(A[j]);
		}
	}
	return false;
}
