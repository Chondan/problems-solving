#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x);
};

int main(void) {
	Solution solution;
	int ans = solution.mySqrt(2147483647);
	cout << "ans: " << ans << endl;	
}

int Solution::mySqrt(int x) {
	// Binary search tree
    if (x == 0) return 0;
    
    int ans;
    int left = 1, right = x;
    while (true) {
    	int middle = left + (right - left) / 2;

    	if (middle > x / middle) {
    		right = middle - 1;
    	} else {
    		if ((middle + 1) > x / (middle + 1)) {
    			ans = middle;
    			break;
    		}
    		left = middle + 1;
    	}
    }
    return ans;
}