#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target);
};

int main(void) {
    Solution solution;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'g';
    char ans = solution.nextGreatestLetter(letters, target);
    cout << "ans: " << ans << endl;
}

char Solution::nextGreatestLetter(vector<char> &letters, char target) {
    int len = letters.size();

    // Not found
    if (target >= letters[len - 1]) return letters[0];

    int l = 0, r = len - 1;
    int ansIndex;
    while (l <= r) {
        int middle = (l + r) / 2;
        int candidate = letters[middle];

        // Go to the left (need to find smallest)
        if (candidate > target) {
            r = middle - 1;
            ansIndex = middle;
        } else {
            l = middle + 1;
        }
    }

    return letters[ansIndex];
}