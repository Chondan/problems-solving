#include <climits>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices);
};

int main(void) {
	Solution solution;
	vector<int> input = {7, 1, 5, 3, 6, 4};
	int ans = solution.maxProfit(input);
	cout << "ans: " << ans << endl;
}

int Solution::maxProfit(vector<int> &prices) {

	int profit = 0;
	int lastPrice = INT_MAX;
	int buyPrice;

	for (auto price: prices) {
		if (price < lastPrice) {
			buyPrice = price;
		} else {
			profit += price - lastPrice;
		}
		lastPrice = price;
	}
	return profit;
}