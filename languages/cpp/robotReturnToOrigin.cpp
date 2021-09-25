#include <iostream>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves);
};

int main(void) {
    Solution solution;
    string moves = "LDRRLRUULR";
    bool ans = solution.judgeCircle(moves);
    cout << "ans: " << ans << endl;
}

bool Solution::judgeCircle(string moves) {
    int moveR = 0, moveU = 0;

    for (char move: moves) {
        switch (move) {
            case 'U':
                moveU++;
                break;
            case 'D':
                moveU--;
                break;
            case 'R':
                moveR++;
                break;
            case 'L':
                moveR--;
                break;
            default:
                break;
        }
    }

    return moveR == 0 && moveU == 0;
}