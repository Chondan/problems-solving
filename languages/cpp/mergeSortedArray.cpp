#include <list>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void displayVector(vector<T> input) {
	for (auto i: input) {
		cout << i << " ";
	}
	cout << endl;
}

class Solution {
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);

};

int main(void) {
	Solution solution;

	vector<int> nums1 = {2, 5, 9, 0, 0, 0};
	int m = 3;
	vector<int> nums2 = {4, 6, 8};
	int n = 3;

	solution.merge(nums1, m, nums2, n);
	displayVector<int>(nums1);
}

void Solution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	
	int cur1 = m - 1;
	int cur2 = n - 1;
	int pos = m + n - 1;

	while (cur1 >= 0 && cur2 >= 0) {
		if (nums1[cur1] > nums2[cur2]) {
			nums1[pos--] = nums1[cur1--];
		} else {
			nums1[pos--] = nums2[cur2--];
		}
	}

	while (cur2 >= 0) {
		nums1[pos--] = nums2[cur2--];
	}
}
