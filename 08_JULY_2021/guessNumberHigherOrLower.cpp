#include <iostream>
using namespace std;

class Solution {
private:
    int pickedNumber;
public:
    Solution(int pick): pickedNumber(pick) {};
    int guessNumber(int n);
    int guess(int num);
};

int main(void) {
    Solution solution(2);
    int n = 2;
    int ans = solution.guessNumber(n);
    cout << "ans: " << ans << endl;
}

int Solution::guessNumber(int n) {
    int l = 1, r = n;
    int ans;
    while (l <= r) {
        int middle = l + (r-l)/2;
        if (this->guess(middle) == 0) {
            ans = middle;
            break;
        }
        if (this->guess(middle) == 1) {
            l = middle + 1;
        }
        if (this->guess(middle) == -1) {
            r = middle - 1;
        }
    }
    return ans;
}

int Solution::guess(int num) {
    if (this->pickedNumber < num) return -1;
    if (this->pickedNumber > num) return 1;
    return 0;
}