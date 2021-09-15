#include <sstream>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

vector<string> split(string s, string delim) {
    vector<string> result;
    int pos = s.find(delim);
    while (pos != -1) {
       string token = s.substr(0, pos);
       result.push_back(token);
       s = s.substr(pos + 1);
       pos = s.find(delim);
    }
    result.push_back(s);
    return result;
}

class Solution {
public:
    bool wordPattern(string pattern, string s);
    bool wordPattern2(string pattern, string s);
};

int main(void) {
    Solution solution;
    string pattern = "abba", s = "dog cat cat fish";
    bool ans = solution.wordPattern(pattern, s);
    cout << "ans: " << ans << endl;
}

bool Solution::wordPattern(string pattern, string s) {
    vector<string> arr = split(s, " ");
    unordered_map<char, string> memo;
    unordered_map<string, char> reveres;

    if (pattern.length() != arr.size()) return false;

    for (int i = 0; i < pattern.length(); i++) {
        char c = pattern[i];
        string word = arr[i];
        if (memo.find(c) == memo.end() && reveres.find(word) == reveres.end()) {
                memo[c] = word;
                reveres[word] = c;
        } else if (!(memo[c] == word && reveres[word] == c)) {
            return false;
        }
    }

    return true;
}

bool Solution::wordPattern2(string pattern, string s) {
    stringstream ss(s);
    string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }

    if (pattern.length() != count) return false;

    ss.clear();
    ss.str(s);
    unordered_map<char, string> CToS;
    unordered_map<string, char> SToC;
    int i = 0;
    while (ss >> word) {
        cout << "word: " << word << endl;
        char c = pattern[i];
        if (CToS.find(c) == CToS.end() && SToC.find(word) == SToC.end()) {
            CToS[c] = word;
            SToC[word] = c;
        } else if (!(CToS[c] == word && SToC[word] == c)) {
            return false;
        }
        i++;
    }

    return true;
}
