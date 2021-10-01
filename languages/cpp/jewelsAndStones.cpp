#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones);
};

int main(void) {
    Solution solution;
    string jewels = "aA", stones = "aAAbbbb";
    int ans = solution.numJewelsInStones(jewels, stones);
    cout << "ans: " << ans << endl;
}

int Solution::numJewelsInStones(string jewels, string stones) {
    unordered_map<char, int> memo;

    int ans = 0;
    for (char stone: stones) {

        if (memo[stone] == 0) {
            for (char jewel: jewels) {
                if (jewel == stone) {
                    memo[stone] = 1;
                    ans += 1;
                    break;
                }
            }
        } else {
            memo[stone]++;
            ans += 1;
        }
    }

    return ans;
}