#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

template <typename T>
void swapp(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

class Solution {
public:
    void reverseString(vector<char> &s);
};

int main(void) {
    Solution solution;
    vector<char> input1 = {'h', 'e', 'l', 'l', 'o'};
    vector<char> input2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    cout << "ans: " << endl;
    solution.reverseString(input1);
    displayVector(input1);
}

void Solution::reverseString(vector<char> &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        swap(s[l], s[r]);
        l++;
        r--;
    }
}