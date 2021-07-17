#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n);
};

int main(void) {
    Solution solution;
    int n = 10;
    int ans = solution.fib(n);
    cout << "ans: " << ans << endl;
}

int Solution::fib(int n) {
    if (n == 0 || n == 1) return n;

    vector<int> memo(n+1);
    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}