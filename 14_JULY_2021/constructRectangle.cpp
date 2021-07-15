#include <cmath>
#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area);
};

int main(void) {
    Solution solution;
    int area = 2;
    vector<int> ans = solution.constructRectangle(area);
    cout << "ans:" << endl;
    displayVector<int>(ans);
}

vector<int> Solution::constructRectangle(int area) {
    vector<int> ans;
    int sq = sqrt(area);
    while (area % sq != 0) {
        sq--;
    }
    ans.push_back(area / sq);
    ans.push_back(sq);

    return ans;
}