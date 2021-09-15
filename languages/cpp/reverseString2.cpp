#include <iostream>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k);
    // Another approach which is use less memory than the above solution 
    string reverseStr2(string s, int k);
};

int main(void) {
    Solution solution;
    string s = "abcdefg"; 
    int k = 2;
    string ans = solution.reverseStr2(s, k);
    cout << "ans: " << ans << endl; 
}

string Solution::reverseStr(string s, int k) {
    int len = s.length(), len2k = 2*k;
    if (len <= 1) return s;    

    string ans = "";
    for (int i = 0; i < len;) {
      int remainChars = len - i;

      if (remainChars >= len2k || (remainChars < len2k && remainChars >= k)) {
        int charsLen = remainChars >= len2k ? k : remainChars - k;

        // Reverse first k chars
        string start = s.substr(i, k);
        reverse(start.begin(), start.end());

        string remain = s.substr(i + k, charsLen);
        ans += start + remain;

        i += len2k;
      } else {
        string chunk = s.substr(i, remainChars);
        reverse(chunk.begin(), chunk.end());

        ans += chunk;
        i += remainChars;  
      }
    } 

    return ans;
}

string Solution::reverseStr2(string s, int k) {
    int len = s.length();
    for (int i = 0; i < len; i += 2*k) {
        int startReversePos = i, endReversePos = min(i+k, len);
        reverse(s.begin() + startReversePos, s.begin() + endReversePos);
    }
    return s;
}