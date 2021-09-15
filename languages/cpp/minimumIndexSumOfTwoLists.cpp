#include <unordered_map>
#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2);
};

int main(void) {
    Solution solution;
    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    vector<string> ans = solution.findRestaurant(list1, list2);
    cout << "ans:" << endl;
    displayVector<string>(ans);
}

vector<string> Solution::findRestaurant(vector<string> &list1, vector<string> &list2) {
    vector<string> ans;
    unordered_map<string, int> memo;

    // Store index of restaurant in list1
    for (int i = 0; i < list1.size(); i++) {
        memo[list1[i]] = i;
    } 

    int leastIndexSum = INT_MAX;
    for (int j = 0; j < list2.size(); j++) {
        string restaurant = list2[j];
        if (memo.find(restaurant) == memo.end()) continue;

        int indexSum = memo[restaurant] + j;
        if (indexSum > leastIndexSum) continue;

        if (indexSum < leastIndexSum) {
            ans.clear(); 
            leastIndexSum = indexSum;
        }
        ans.push_back(restaurant); 
    }

    return ans;
}