#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices);

};

int main(void) {
	Solution solution;
	vector<int> input = {7, 1, 5, 3, 4, 6};
	vector<int> input2 = {7, 6, 5, 4, 3, 2, 1};

	int ans = solution.maxProfit(input);
	cout << "ans: " << ans << endl;
}

int Solution::maxProfit(vector<int> &prices) {

	int minPrice = INT_MAX;
	int maxProfit = 0;

	for (auto price: prices) {
		minPrice = min(minPrice, price);
		maxProfit = max(maxProfit, price - minPrice);
	}
	return maxProfit;
}
