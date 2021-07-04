#include <iostream>
using namespace std;

class Solution {
private:
    int fBad;
public:
    Solution(int x): fBad(x) {}
    int firstBadVersion(int n);
    bool isBadVersion(int version);
};

int main(void) {
    int fBad = 2;
    Solution solution(fBad);
    int version = 3;
    int ans = solution.firstBadVersion(version);
    cout << "ans: " << ans << endl;
}

int Solution::firstBadVersion(int n) {

    int l = 1, r = n;
    while (l < r) {
        int middle = l/2 + r/2;
        if (this->isBadVersion(middle)) {
            r = middle - 1;
        } else {
            l = middle + 1;
        }
    }

    return this->isBadVersion(l) ? l : l + 1;
}

bool Solution::isBadVersion(int version) {
    if (version >= this->fBad) return true;
    return false;
}