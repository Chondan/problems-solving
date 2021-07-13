#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn);
    vector<int> valid_bit_generator(int len, int max_bit_count, int value_limit);
};

int main(void) {
    Solution solution;
    int turnedOn = 5;
    vector<string> ans = solution.readBinaryWatch(turnedOn);
    cout << "ans:" << endl;
    displayVector<string>(ans);
}

vector<string> Solution::readBinaryWatch(int turnedOn) {
    vector<string> ans;
    vector<int> hours;
    vector<int> minutes;
    for (int i = 0; i <= turnedOn; i++) {
        hours = valid_bit_generator(4, i, 11);
        minutes = valid_bit_generator(6, turnedOn - i, 59);
        for (int hour: hours) {
            for (int minute: minutes) {
                string h = to_string(hour);
                string m = minute < 10 ? "0" + to_string(minute) : to_string(minute);
                string time = h + ":" + m;
                ans.push_back(time); 
            }
        }
    }

    return ans;
}

vector<int> Solution::valid_bit_generator(int len, int max_bit_count, int value_limit) {
    // Maximum value that can be -> (1 << len) is equal to 2 ^ len
    int total = 1 << len;
    vector<int> result;
    for (int i = 0; i < total; i++) {
        int counter = 0;
        for (int j = 0; j < len; j++) {
            // 1 << j is mean 2 ^ j
            if (i & (1 << j)) {
                // To check that j can be constructed to i
                // e.g. 5 (101) = 4 (100) + 1 (001)
                counter++;
            }
        }
        if (counter == max_bit_count && i <= value_limit) {
            result.push_back(i);
        }
    }
    return result;
}
