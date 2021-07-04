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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

class Solution {
public:
    void moveZeroes(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> input = {0, 0, 1, 0, 3, 12, 0, 0, 14, 15};
    solution.moveZeroes(input);
    cout << "ans: " << endl;
    display(input);
}

void Solution::moveZeroes(vector<int> &nums) {

    int len = nums.size();
    int zeroIndex = - 1;
    for (int i = 0; i < len; i++) {
        // Found first zero
        if (zeroIndex == -1 && nums[i] == 0) zeroIndex = i;

        if (nums[i] != 0 && zeroIndex != -1) {
            swap(nums[i], nums[zeroIndex]);

            // Update zeroIndex
            zeroIndex++;
        }
    }

}