#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string> &operations);
};

int main(void) {
    Solution solution;
    vector<string> operations = {"X++","++X","--X","X--"};
    int ans = solution.finalValueAfterOperations(operations);
    cout << "ans: " << ans << endl;
}

int Solution::finalValueAfterOperations(vector<string> &operations) {
    int value = 0;
    for (string operation: operations) {
        char symbol = operation[0] ^ operation[2] ^ 'X';
        value += symbol == '+' ? 1 : -1;
    }

    return value;
}