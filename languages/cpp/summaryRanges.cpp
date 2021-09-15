#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void display(vector<T> input) {
    for (auto i: input) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums);
    string getSummary(int start, int end);
};

int main(void) {
    Solution solution;
    vector<int> input = {0,1,2,4,5,7};
    vector<string> ans = solution.summaryRanges(input);
    cout << "ans: " << endl;
    display<string>(ans);
}

vector<string> Solution::summaryRanges(vector<int> &nums) {
    
    int len = nums.size();
    vector<string> ans;
    if (nums.size() == 0) return ans;
    if (nums.size() == 1) {
        ans.push_back(to_string(nums[0]));
        return ans;
    }
    
    int startPos = 0, lastPos = len - 1; 
    for (int i = 1;i < len; i++) {
        int num = nums[i], prevNum = nums[i - 1];
        if (num - 1 > prevNum) {
            int endPos = i - 1;
            ans.push_back(this->getSummary(nums[startPos], nums[endPos]));
            startPos = i;
        }
    }
    ans.push_back(this->getSummary(nums[startPos], nums[lastPos]));

    return ans;
}

string Solution::getSummary(int start, int end) {
    string summary;
    if (start == end) {
        summary = to_string(start);
    } else {
        summary = to_string(start) + "->" + to_string(end);
    }
    return summary;
}