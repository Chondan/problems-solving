#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string> &words);
};

int main(void) {
    Solution solution;
    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    vector<string> ans = solution.findWords(words);
    cout << "ans:" << endl;
    displayVector<string>(ans);
}

vector<string> Solution::findWords(vector<string> &words) {
    vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    unordered_map<char, int> memo;

    int rowNum = 0;
    for (string row: rows) {
        for (char c: row) {
            memo[c] = rowNum;
        }
        rowNum++;
    }

    vector<string> ans;
    for (string word: words) {
        int startingRow = memo[tolower(word[0])];
        bool isInTheSameRow = true;
        for (int i = 1; i < word.length(); i++) {
            char c = tolower(word[i]);
            if (memo[c] != startingRow) {
                isInTheSameRow = false;
                break;
            }
        }
        if (!isInTheSameRow) continue;
        ans.push_back(word);
    }

    return ans;
}