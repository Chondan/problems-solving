#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration);
};

int main(void) {
    Solution solution;
    vector<int> timeSeries = {1, 3, 4};
    int duration = 2;
    int ans = solution.findPoisonedDuration(timeSeries, duration);
    cout << "ans: " << ans << endl;
}

int Solution::findPoisonedDuration(vector<int> &timeSeries, int duration) {
    // Starting duration for the last attack
    int ans = duration;

    for (int i = 0; i < timeSeries.size() - 1; i++) {
        int attackUntil = min(timeSeries[i] + duration, timeSeries[i + 1]);
        int poisonedDuration = attackUntil - timeSeries[i];
        ans += poisonedDuration;
    }

    return ans; 
}
