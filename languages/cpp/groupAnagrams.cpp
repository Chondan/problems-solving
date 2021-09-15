#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

string sortString(string str) {
	string result = str;
	sort(result.begin(), result.end());
	return result;
}

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string> &strings);
};

int main(void) {
	Solution solution;
	vector<string> input = {"eat","tea","tan","ate","nat","bat"};
	vector<vector<string>> ans = solution.groupAnagrams(input);

	for (int i = 0; i < ans.size(); i++) {
		cout << "group: " << i << endl;
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << endl;
		}
	}
}

vector<vector<string>> Solution::groupAnagrams(vector<string> &strings) {
	unordered_map<string, int> memo;
	unordered_map<string, vector<string>> result;
	for (auto str: strings) {
		string sortedString = sortString(str);
		unordered_map<string, int>::iterator s = memo.find(sortedString);

		if (s == memo.end()) {
			memo[sortedString] = 1;
			result[sortedString].push_back(str);
		} else {
			result[sortedString].push_back(str);
		}
	}

	vector<vector<string>> groupAnagrams;
	for (auto res: result) {
		groupAnagrams.push_back(res.second);
	}
	return groupAnagrams;
}