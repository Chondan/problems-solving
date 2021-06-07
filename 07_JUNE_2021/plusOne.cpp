#include <vector>
#include <iostream>
using namespace std;

template <typename T>
vector<T> reverse(vector<T> input) {
	vector<T> reveres;
	for (int i = input.size() - 1; i >= 0; i--) {
		reveres.push_back(input[i]);
	}
	return reveres;
}

template <typename T>
void displayList(vector<T> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	} 
	cout << endl;
}

class Solution {
public:
	vector<int> plusOne(vector<int> &digits);
	vector<int> plusOne2(vector<int> &digits);
};

int main(void) {
	Solution solution;
	vector<int> input = {2, 9, 9};
	// vector<int> ans = solution.plusOne(input);
	vector<int> ans = solution.plusOne2(input);

	displayList<int>(ans);
}

vector<int> Solution::plusOne(vector<int> &digits) {
	vector<int> ans;

	int memo = 1;
	int sum;
	for (int i = digits.size() - 1; i >= 0; i--) {
		sum = memo + digits[i];
		if (sum >= 10) {
			memo = 1;
			ans.push_back(0);
		} else {
			memo = 0;
			ans.push_back(sum);
		}
	}
	if (memo == 1) ans.push_back(1);

	return reverse<int>(ans); 
}

vector<int> Solution::plusOne2(vector<int> &digits) {
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits[i] == 9) {
			digits[i] = 0;
		} else {
			digits[i] += 1;
			return digits;
		}
	}
	digits[0] = 1;
	digits.push_back(0);
	return digits;
}





















