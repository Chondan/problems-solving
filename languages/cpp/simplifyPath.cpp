#include <stack>
#include <vector>
#include <iostream>
#include "utils/util.h"
using namespace std;

class Solution {
public:
    string simplifyPath(string path);
    vector<string> split(string str, char delimiter);
};

int main(void) {
    Solution solution;
    string path = "/a//b////c/d//././/..";
    string ans = solution.simplifyPath(path);
    cout << "ans: " << ans << endl;
}

string Solution::simplifyPath(string path) {
    vector<string> splitPath = this->split(path, '/');
    stack<string> memo;

    for (string path: splitPath) {
        cout << "path: " << path << endl;
        if (path == ".") {
            continue;
        }
        else if (path == "..") {
            if (memo.empty()) continue;
            memo.pop();
        }
        else {
            memo.push(path);
        }
    }

    string ans = "";
    while (!memo.empty()) {
        string top = memo.top();
        memo.pop();
        ans = "/" + top + ans;
    }

    return ans == "" ? "/" : ans;
}

vector<string> Solution::split(string str, char delimiter) {
    vector<string> result;
    string word = "";
    // To make sure that string that we are goint to loop through will end up with "/"
    string copyStr = str + "/";

    for (int i = 0; i < copyStr.length(); i++) {
        char c = copyStr[i];

        if (c == '/') {
            // Check word
            if (word != "") result.push_back(word);

            word = "";
        } else {
            word += c;
        }
    }

    return result;
}

