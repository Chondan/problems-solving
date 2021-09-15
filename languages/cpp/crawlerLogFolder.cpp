#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(vector<string> &logs);
};

int main(void) {
    Solution solution;
    vector<string> logs = {"d1/","d2/","./","d3/","../","d31/"};
    int ans = solution.minOperations(logs);
    cout << "ans: " << ans << endl; 
}

int Solution::minOperations(vector<string> &logs) {
    int depth = 0;
    for (int i = 0; i < logs.size(); i++) {
        string log = logs[i];

        if (log == "./") continue;

        if (log == "../") {
            if (depth == 0) continue;
            depth--;
        } else {
            depth++;
        }
    }

    return depth;
}