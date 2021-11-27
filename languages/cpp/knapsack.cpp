// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int knapsack(vector<int> weights, vector<int> values, int capacity);
	int helper(vector<int> weights, vector<int> values, int capacity, int candidateWeightIndex);
	// Memoization
	unordered_map<string, int> memo;
};

int main(void) {
	Solution solution;
	vector<int> weights = {10, 20, 30};
	vector<int> values = {60, 100, 120};
	int capacity = 50;
	int ans = solution.knapsack(weights, values, capacity);
	cout << "ans: " << ans << endl;
}

int Solution::knapsack(vector<int> weights, vector<int> values, int capacity) {
	int candidateWeightIndex = weights.size() - 1;
	return this->helper(weights, values, capacity, candidateWeightIndex);
}

int Solution::helper(vector<int> weights, vector<int> values, int capacity, int candidateWeightIndex) {
	// --- Memoization ---
	string key = to_string(capacity) + ":" + to_string(candidateWeightIndex);
	if (this->memo.find(key) != this->memo.end()) return this->memo[key];

	// Base case -> out of index OR no capacity left			
	if (capacity == 0 || candidateWeightIndex < 0) return 0;

	// Not enough capacity (can't take the candidate weight)
	if (capacity < weights[candidateWeightIndex]) {
		return this->helper(weights, values, capacity, candidateWeightIndex - 1);
	}

	// --- We have 2 choices here ---
	// Select the candidate
	int remainingCapacity = capacity - weights[candidateWeightIndex];
	int option1 = values[candidateWeightIndex] + this->helper(weights, values, remainingCapacity, candidateWeightIndex - 1);

	// Not select the candidate
	int option2 = this->helper(weights, values, capacity, candidateWeightIndex - 1);
	memo[key] = max(option1, option2);

	return memo[key];
}