#include <vector>
#include <iostream>
#include "./utils/util.h"
using namespace std;

class NumArray {
private:
    vector<int> items;
public:
    NumArray(vector<int>  &nums);
    int sumRange(int left, int right);


};

// Another approach to use prefix sum
class NumArray2 {
private:
    vector<int> items;
    vector<int> prefixSum;
public:
    NumArray2(vector<int>  &nums);
    int sumRange(int left, int right);   
};

int main(void) {
    vector<int> numArray = {-2, 0, 3, -5, 2, -1};
    NumArray2 *obj = new NumArray2(numArray);
    cout << obj->sumRange(0, 2) << endl;
    cout << obj->sumRange(2, 5) << endl;
    cout << obj->sumRange(0, 5) << endl;
}

// ----- NumArray -----
NumArray::NumArray(vector<int> &nums) {
    this->items = nums;
}

int NumArray::sumRange(int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; i++) {
        sum += this->items[i];
    }
    return sum;
}

// ----- NumArray2 -----
NumArray2::NumArray2(vector<int> &nums) {
    this->items = nums;
    // items -> 1 2 3 4 5
    // prefixSum -> 1 3 6 10 15
    // sumRange(a, b) = prefixSum[b] - prefixSum[a - 1] 

    vector<int> prefixSum(nums.size(), 0);
    this->prefixSum = prefixSum; 
    this->prefixSum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        this->prefixSum[i] = nums[i] + this->prefixSum[i - 1];
    }
}

int NumArray2::sumRange(int left, int right) {
    int diff = left == 0 ? 0 : this->prefixSum[left - 1];
    return this->prefixSum[right] - diff;
}
