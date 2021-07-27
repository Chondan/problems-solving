#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n);
};

int main(void) {
    Solution solution;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    bool ans = solution.canPlaceFlowers(flowerbed, n);
    cout << "ans: " << ans << endl;
}

bool Solution::canPlaceFlowers(vector<int> &flowerbed, int n) {
    // Preparing array to loop by inserting 0 at the beginning and at the end
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);

    int flowersToPlant = n;
    for (int i = 1; i < flowerbed.size() - 1; i++) {
        if (flowersToPlant == 0) break; 
        
        int isPlanted = flowerbed[i];
        if (isPlanted) continue;

        bool canPlant = flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0;
        if (canPlant) {
            flowerbed[i] = 1;
            flowersToPlant--;
        }
    }

    return flowersToPlant == 0 ? true : false;
}