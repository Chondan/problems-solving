#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int> &candyType);
};

int main(void) {
    Solution solution;
    vector<int> candyType = {1,1,2,2,3,3,4};
    int ans = solution.distributeCandies(candyType);
    cout << "ans: " << ans << endl;
}

int Solution::distributeCandies(vector<int> &candyType) {
    int canEat = candyType.size() / 2;

    unordered_set<int> distinctCandyType;
    for (int candy: candyType) {
        distinctCandyType.insert(candy);
    }

    int distinctCandyTypeLen = distinctCandyType.size();
    return canEat <= distinctCandyTypeLen ? canEat : distinctCandyTypeLen;
}