#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits);
};

int main(void) {
    Solution solution;
    vector<int> bits = {1,1,1,0};
    bool ans = solution.isOneBitCharacter(bits);
    cout << "ans: " << ans << endl;
}

bool Solution::isOneBitCharacter(vector<int> &bits) {
    int lastestBit;
    for (int i = 0; i < bits.size(); i++) {
        int bit = bits[i];
        lastestBit = bit;
        if (bit == 1) i += 1;
    }

    return lastestBit == 0;
}