#include <iostream>
#include <vector>
using namespace std;

/* 
	You are given a string 's' of lowercase English letters 
	and an array 'widths' denoting "how many pixels wide" each 
	lowercase English letter is. Specifically, 'widths[0]' is 
	the width of 'a', 'widths[1]' is the width of 'b', and so on

	You are trying to write 's' across several lines, where 
	"each line is no longer than '100' pixels". Starting at 
	the beginning of 's', write as many letters on the first line 
	such that the total width does not exceed '100' pixels. 
	Then, from where you stopped in 's', continue writing as 
	many letter as you can on the second line. Continue this 
	process until you have written all of 's'.

	Return an array 'result' of length 2 where:
	1. result[0] is the total number of lines.
	2. result[1] is the width of the last line in pixels.
*/
class Solution {
private:
	const int MAX_WIDTH_OF_LINE = 100;
	int getWidthOfChar(vector<int> &widths, char c);
public:
	vector<int> numberOfLines(vector<int> &widths, string s);
	vector<int> simpleNumberOfLines(vector<int> &widths, string s);
};

int main(void) {
	Solution *solution = new Solution();

	vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
	string s = "abcdefghijklmnopqrstuvwxyz";

	vector<int> ans = solution->numberOfLines(widths, s);
	int numberOfLines = ans[0];
	int widthOfLastLine = ans[1];

	cout << "numberOfLines: " << numberOfLines << endl;
	cout << "widthOfLastLine: " << widthOfLastLine << endl;
}

vector<int> Solution::numberOfLines(vector<int> &widths, string s) {
	int lines = 1, currentWidthOfLine = 0;	
	int stringLen = s.length();

	for (int i = 0; i < stringLen; i++) {
		char c = s[i];
		int widthOfChar = this->getWidthOfChar(widths, c);
		currentWidthOfLine += widthOfChar;

		if (currentWidthOfLine == MAX_WIDTH_OF_LINE) {
			bool IsLastIndex = i == stringLen - 1;

			lines = IsLastIndex ? lines : lines + 1;
			currentWidthOfLine = IsLastIndex ? currentWidthOfLine : 0;
		} else if (currentWidthOfLine > MAX_WIDTH_OF_LINE) {
			lines += 1;
			currentWidthOfLine = widthOfChar;
		}
	}

	vector<int> ans = {lines, currentWidthOfLine};
	return ans;
}

vector<int> Solution::simpleNumberOfLines(vector<int> &widths, string s) {
	int lines = 1, currentWidthOfLine = 0;	

	for (char c: s) {
		int widthOfChar = this->getWidthOfChar(widths, c);
		bool isNewLine = currentWidthOfLine + widthOfChar > MAX_WIDTH_OF_LINE
		lines = isNewLine ? lines + 1 : lines;
		currentWidthOfLine = isNewLine ? widthOfChar : currentWidthOfLine + widthOfChar;
	}

	vector<int> ans = {lines, currentWidthOfLine};
	return ans;
}

int Solution::getWidthOfChar(vector<int> &widths, char c) {
	return widths[c - 'a'];
}

