#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
#define NOT_FOUND -1

// Write a function which return the majority element (if it exists), 
// otherwise return -1. 

// A majority element in an array A[] of size n 
// is an element that appears more than n/2 times 
// (and hence there is at most one such element). 

class Solution {
public:
    int majorityElement(vector<int> &nums);
    // Moore's voting algorithm
    int majorityElement2(vector<int> &nums);
    int getCandidate(vector<int> &nums);
    int isMajority(vector<int> &nums, int candidate);
};

int main(void) {
	Solution solution;
	vector<int> input = {2, 2, 3, 4, 1, 2};
	int ans = solution.majorityElement2(input);
	cout << "ans: " << ans << endl;
}

int Solution::majorityElement(vector<int> &nums) {
	int lowerBound = nums.size() / 2;

	unordered_map<int, int> memo;
	int ans;
	for (int i = 0; i < nums.size(); i++) {
		int num = nums[i];
		if (memo.find(num) == memo.end()) {
			memo[num] = 0;
			memo[num]++;
		} else {
			memo[num]++;
			
		}
		if (memo[num] > lowerBound) {
			ans = num;
			break;
		}
	}
	return ans;
}

// Function to find the candidate for Majority
int Solution::getCandidate(vector<int> &nums) {
	int count = 1, majorIndex = 0, candidate = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		int num = nums[i];

		if (num  == candidate) count++;
		else count--;

		if (count == 0) {
			candidate = num;
			count = 1;
		}
	}
	return candidate;
}

// Function to check if the candidate 
// occurs more than n/2 times
int Solution::isMajority(vector<int> &nums, int candidate) {
	int count = 0;
	for (auto num: nums) {
		if (num == candidate) count++;
	}
	return count > nums.size() / 2 ? true : false;
}


int Solution::majorityElement2(vector<int> &nums) {
	int candidate = this->getCandidate(nums);
	int isCandidateMajority = this->isMajority(nums, candidate);
	return isCandidateMajority ? candidate : NOT_FOUND;
}














