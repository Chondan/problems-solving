#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int calPoints(vector<string> &ops);
};

int main(void) {
    Solution solution;
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    int ans = solution.calPoints(ops);
    cout << "ans: " << ans << endl;
}

int Solution::calPoints(vector<string> &ops) {
    int ans = 0;
    vector<int> scores;
    int lastIndexScore = -1;

    int score;
    for (string op: ops) {
        if (op == "C") {
            score = -1 * scores[lastIndexScore];
            ans += score;
            scores.pop_back();
            lastIndexScore--;
            continue;
        } else if (op == "D") {
            score = 2 * scores[lastIndexScore];
        } else if (op == "+") {
            score = scores[lastIndexScore] + scores[lastIndexScore - 1];
        } else {
            score = stoi(op);
        }

        ans += score;
        scores.push_back(score);
        lastIndexScore++;
    }

    return ans;
}
