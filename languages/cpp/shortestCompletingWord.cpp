#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words);
    string getOnlyLowerCaseAlphabetsFromLicensePlate(string licensePlate);
};

int main(void) {
    Solution solution;
    string licensePlate = "1s3 456";
    vector<string> words = {"looks","pest","stew","show"};
    string ans = solution.shortestCompletingWord(licensePlate, words);
    cout << "ans: " << ans << endl;
}

string Solution::shortestCompletingWord(string licensePlate, vector<string> &words) {
    string onlyLowerCaseAlphabetsFromLicensePlate = this->getOnlyLowerCaseAlphabetsFromLicensePlate(licensePlate);

    string ans = "";
    for (string word: words) {
        string copyOfOnlyLowerCaseAlphabetsFromLicensePlate = onlyLowerCaseAlphabetsFromLicensePlate;
        int copyOfOnlyLowerCaseAlphabetsFromLicensePlateLen = copyOfOnlyLowerCaseAlphabetsFromLicensePlate.length();

        for (char w: word) {
            for (int i = 0; i < copyOfOnlyLowerCaseAlphabetsFromLicensePlate.length(); i++) {
                if (w == copyOfOnlyLowerCaseAlphabetsFromLicensePlate[i]) {
                    char unAllowedCharInWord = ' ';
                    copyOfOnlyLowerCaseAlphabetsFromLicensePlate[i] = unAllowedCharInWord;
                    copyOfOnlyLowerCaseAlphabetsFromLicensePlateLen--; // The matched character is removed from onlyLowerCaseAlphabetsFromLicensePlate
                    break;
                }
            }
        }

        if (copyOfOnlyLowerCaseAlphabetsFromLicensePlateLen == 0) {
            ans = word.length() < ans.length() || ans.length() == 0 ? word : ans;
        }
    }

    return ans;
}

string Solution::getOnlyLowerCaseAlphabetsFromLicensePlate(string licensePlate) {

    string onlyLowerCaseAlphabetsFromLicensePlate = "";
    for (char c: licensePlate) {
        // Filter out number
        bool isNum = c - '0' >= 0 && c - '0' <= 9;
        bool isWhiteSpace = c == ' ';
        if (isNum || isWhiteSpace) continue;

        char lowerC = tolower(c);
        onlyLowerCaseAlphabetsFromLicensePlate += lowerC;
    }

    return onlyLowerCaseAlphabetsFromLicensePlate;
}

/* 

1. fitler out alphabets from licentsPlate and turn all of it into lower case
onlyLowerAlphabets <- getOnlyLowercaseAlphabetsFromLicensePlate(string licensePlate)

2. the result from 1 will use to be as an original so that we gonna copy it
    - copy it into other variables
    - loop nested loop (licensePlate and word) -> replace all occurence of alphabets in word from licensePlate
    - licensePlate should be "" if that word contains all of the alphabets

3. store the value from 2 in variable called 'shortesWord'
    - if there is new value, compare it with the old one
        - if newLen < oldLen then replace it with the new one
        - else do nothing

*/