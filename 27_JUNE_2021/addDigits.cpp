#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num);
    int addDigits2(int num);
};

int main(void) {
    Solution solution;
    int num = 38;
    int ans = solution.addDigits2(num); // 2
    cout << "ans: " << ans << endl;
}

int Solution::addDigits(int num) {
    if (num < 10) return num;

    int temp = num;
    int sum = 0;
    while (temp > 0) {
        sum = sum + (temp % 10);
        temp /= 10;
    }
    return this->addDigits(sum);
}

// Another approach using math
int Solution::addDigits2(int num) {
    if (num == 0) {
        return 0;
    } else if (num % 9 == 0) {
        return 9;
    } else {
        return num % 9;
    }
}