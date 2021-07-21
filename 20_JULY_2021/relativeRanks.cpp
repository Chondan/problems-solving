#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &score);
};

int main(void) {
    Solution solution;
    vector<int> score = {10, 3, 8, 9, 4};
    vector<string> ans = solution.findRelativeRanks(score);
    cout << "ans:" << endl;
    displayVector<string>(ans);
}

vector<string> Solution::findRelativeRanks(vector<int> &score) {
    // Sort max to min
    vector<int> maxToMin = score;
    sort(maxToMin.begin(), maxToMin.end(), greater<int>());

    string medals[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    unordered_map<int, string> memo;
    for (int i = 0; i < maxToMin.size(); i++) {
        if (i < 3) {
            memo[maxToMin[i]] = medals[i];
        } else {
            memo[maxToMin[i]] = to_string(i + 1);
        }
    }

    vector<string> ans;
    for (int s: score) {
        ans.push_back(memo[s]);
    }

    return ans;
}