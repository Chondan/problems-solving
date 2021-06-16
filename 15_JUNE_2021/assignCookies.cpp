#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s);
};

int main(void) {
	Solution solution;
	vector<int> g = {7, 8, 9, 10}; // 7 8 9 10	
	vector<int> s = {5, 6, 7, 8};  // 5 6 7 8	
	int ans = solution.findContentChildren(g, s);
	cout << "ans: " << ans << endl;
}

int Solution::findContentChildren(vector<int> &g, vector<int> &s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());

	int i = 0, j = 0;
	int count = 0;
	while (i < g.size() && j < s.size()) {
		if (s[j] >= g[i]) {
			count++;
			i++;
		}
		j++;
	}
	return count;
}