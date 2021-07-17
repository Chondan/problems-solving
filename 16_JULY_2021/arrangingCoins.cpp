#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n);
};

int main(void) {
    Solution solution;
    int n = 100;
    int ans = solution.arrangeCoins(n);
    cout << "ans: " << ans << endl;
}

int Solution::arrangeCoins(int n) {
    long long int l = 1, r = n;
    while (l <= r) {
        long long int middle = l + (r-l)/2;

        long long int coin = (middle * (middle + 1)) / 2;
        if (coin <= n) {
            l = middle + 1;
        } else {
            r = middle - 1;
        } 
    }
    return l - 1;
}