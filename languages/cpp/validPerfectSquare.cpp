#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num);
};

int main(void) {
    Solution solution;
    int num = 1;
    bool ans = solution.isPerfectSquare(num);
    cout << "ans: " << ans << endl;
}

bool Solution::isPerfectSquare(int num) {
    int l = 1, r = num;
    while (l <= r) {
        long int middle = l + (r - l)/2;
        
        if (middle*middle == num) return true;
        if (middle*middle > num) r = middle - 1;
        if (middle*middle < num) l = middle + 1;        
    }

    return false;
}