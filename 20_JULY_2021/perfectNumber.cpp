#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num);
};

int main(void) {
    Solution solution;
    int num = 496;
    bool ans = solution.checkPerfectNumber(num);
    cout << "ans: " << ans << endl;
}

bool Solution::checkPerfectNumber(int num) {
    if (num == 1) return false;

    int sum = 1;
    for (int i = 2; i < sqrt(num); i++) {
        if (num % i == 0) sum += i + num/i;
    }

    return sum == num ? true : false;
}
